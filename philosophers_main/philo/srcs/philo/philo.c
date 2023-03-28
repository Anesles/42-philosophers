/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 16:26:12 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_nEat(t_data *data, int n)
{
	int	state;
	pthread_mutex_t	lock;

	state = 0;
	lock = data->mtxDataRace;
	pthread_mutex_lock(&lock);
	if (n != data->n_eat)
		state = 1;
	pthread_mutex_unlock(&lock);
	return (state);
}

void	lock_forks(t_data *data, int n)
{
	if (n == data->n_philos)
	{
		pthread_mutex_lock(&(data->forks[0]));
		send_msg(data, n, ACTION_FORK);
		pthread_mutex_lock(&(data->forks[4]));
		send_msg(data, n, ACTION_FORK);
	}
	else
	{	
		pthread_mutex_lock(&(data->forks[n - 1]));
		send_msg(data, n, ACTION_FORK);
		pthread_mutex_lock(&(data->forks[n % data->n_philos]));
		send_msg(data, n, ACTION_FORK);
	}
}

void Eat(t_data *data, t_philo *philo)
{
	if (check_continue(data))
		return ;
	lock_forks(data, philo->n);
	if (check_continue(data))
		return ;
	send_msg(data, philo->n, ACTION_EATING);
	usleep(data->tte * 1000);
	if (check_continue(data))
		return ;
	pthread_mutex_lock(&(data->mtxForTime));
	if (check_continue(data))
		return ;
	philo->lastAte = get_time();
	pthread_mutex_unlock(&(data->mtxForTime));
	pthread_mutex_unlock(&(data->forks[philo->n - 1]));
	pthread_mutex_unlock(&(data->forks[philo->n % data->n_philos]));
	send_msg(data, philo->n, ACTION_SLEEPING);
}

void	*philo_main(void *info)
{
	t_philo			*philo;
	
	philo = (t_philo *) info;
	while(1)
	{
		if (!check_continue(philo->data))
			break;
	}
	while(philo->data->start)
	{
		if (get_nEat(philo->data, philo->n_eat))
		{
			Eat(philo->data, philo);
			if (check_continue(philo->data))
				break;
			philo->n_eat++;
			usleep(philo->data->tts * 1000);
			if (check_continue(philo->data))
				break;
			send_msg(philo->data, philo->n, ACTION_THINKING);
		}
		else
		{
			philo->hEaten = 1;
			break ;
		}
	}
	return (NULL);
}