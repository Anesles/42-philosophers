/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/22 17:44:22 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checkEnd(t_data *data)
{
	t_philo	*philo;
	int	ended;
	int	i;

	i = 0;
	ended = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&(data->mtxForTime));
		philo = &data->philos[i];
		if (philo->hEat)
			ended++;
		else if ((get_time() - philo->lastAte) >= data->ttd)
		{
			send_msg(data, philo->n, ACTION_DIED);
			data->start = 0;
			break ;
		}
		pthread_mutex_unlock(&(data->mtxForTime));
		i++;
	}
	if (ended == data->n_philos)
		data->start = 0;
}

void canEat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->n - 1]));
	pthread_mutex_lock(&(data->forks[philo->n % philo->data->n_philos]));
	send_msg(data, philo->n, ACTION_FORK);
	send_msg(data, philo->n, ACTION_FORK);
	send_msg(data, philo->n, ACTION_EATING);
	usleep(data->tte * 1000);
	pthread_mutex_lock(&(data->mtxForTime));
	philo->lastAte = get_time();
	pthread_mutex_unlock(&(data->mtxForTime));
	pthread_mutex_unlock(&(data->forks[philo->n - 1]));
	pthread_mutex_unlock(&(data->forks[philo->n % philo->data->n_philos]));
	send_msg(data, philo->n, ACTION_SLEEPING);
}

void *monitor(void *info)
{
	t_data *data;

	data = (t_data *) info;
	while(1)
	{
		if (data->start == 1)
			break ;
	}
	while (data->start)
		checkEnd(data);
	printf("Monitor ended!\n");
	return (0);
}