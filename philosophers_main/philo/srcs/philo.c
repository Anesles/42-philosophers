/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/05 16:14:46 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkNEat(t_data *data, int n)
{
	int	state;

	state = 0;
	if (n != data->n_eat)
		state = 1;
	return (state);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->lfork]));
	pthread_mutex_lock(&(philo->data->forks[philo->rfork]));
	sendMsg(philo, ACTION_FORK);
	sendMsg(philo, ACTION_FORK);
	pthread_mutex_lock(&(philo->data->eat));
	sendMsg(philo, ACTION_EATING);
	philo->last_ate = getTime();
	pthread_mutex_unlock(&(philo->data->eat));
	usleep(philo->data->tte * 1000);
	pthread_mutex_lock(&(philo->data->times_eat_mutex));
	philo->times_eat++;
	pthread_mutex_unlock(&(philo->data->times_eat_mutex));
	pthread_mutex_unlock(&(philo->data->forks[philo->rfork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->lfork]));
}

void	*philoMain(void *info)
{
	t_philo	*philo;
	t_data	*data;
	
	philo = (t_philo *) info;
	data = philo->data;
	if (philo->n % 2)
		usleep(data->tte / 50);
	if (data->n_philos == 1)
	{
		pthread_mutex_lock(&data->forks[philo->lfork]);
		sendMsg(philo, ACTION_FORK);
		pthread_mutex_lock(&(data->eat));
		philo->last_ate = getTime();
		pthread_mutex_unlock(&(data->eat));
		pthread_mutex_unlock(&data->forks[philo->lfork]);
		return (NULL);
	}
	while(!check_stop(data) && checkNEat(data, philo->times_eat))
	{
		if (philo->data->n_philos != 1)
		{
			eating(philo);
			sendMsg(philo, ACTION_SLEEPING);
			usleep(data->tts * 1000);
			sendMsg(philo, ACTION_THINKING);
		}
	}
	return (NULL);
}