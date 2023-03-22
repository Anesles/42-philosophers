/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/22 15:26:38 by brumarti         ###   ########.fr       */
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
		pthread_mutex_lock(&(data->forks[data->n_philos]));
		philo = &data->philos[i];
		if (philo->hEat)
			ended++;
		else if ((get_time() - philo->lastAte) >= data->ttd)
		{
			send_msg(data, philo->n, "has died.");
			end_simulation(data);
		}
		pthread_mutex_unlock(&(data->forks[data->n_philos]));
		i++;
	}
	if (ended == data->n_philos)
	{
		printf("Everyone ate %d times !", data->n_eat);
		end_simulation(data);
	}
}

void canEat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->n - 1]));
	pthread_mutex_lock(&(data->forks[philo->n % philo->data->n_philos]));
	send_msg(data, philo->n, "has taken fork.");
	send_msg(data, philo->n, "has taken fork.");
	pthread_mutex_lock(&(data->forks[data->n_philos]));
	philo->lastAte = get_time();
	pthread_mutex_unlock(&(data->forks[data->n_philos]));
	send_msg(data, philo->n, "started eating.");
	usleep(data->tte * 1000);
	pthread_mutex_unlock(&(data->forks[philo->n - 1]));
	pthread_mutex_unlock(&(data->forks[philo->n % philo->data->n_philos]));
	send_msg(data, philo->n, "is sleeping.");
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
	while (1)
	{
		checkEnd(data);
		usleep(1000);
	}
	return (0);
}