/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/05 18:10:37 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_n_eat(t_data *data, int n)
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
	send_msg(philo, ACTION_FORK);
	send_msg(philo, ACTION_FORK);
	pthread_mutex_lock(&(philo->data->eat));
	send_msg(philo, ACTION_EATING);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&(philo->data->eat));
	usleep(philo->data->tte * 1000);
	pthread_mutex_lock(&(philo->data->times_eat_mutex));
	philo->times_eat++;
	pthread_mutex_unlock(&(philo->data->times_eat_mutex));
	pthread_mutex_unlock(&(philo->data->forks[philo->rfork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->lfork]));
}

void	*philo_main(void *info)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) info;
	data = philo->data;
	if (philo->n % 2)
		usleep(data->tte / 50);
	if (data->n_philos == 1)
	{
		send_msg(philo, ACTION_FORK);
		return (NULL);
	}
	while (!check_stop(data) && check_n_eat(data, philo->times_eat))
	{
		if (philo->data->n_philos != 1)
		{
			eating(philo);
			send_msg(philo, ACTION_SLEEPING);
			usleep(data->tts * 1000);
			send_msg(philo, ACTION_THINKING);
		}
	}
	return (NULL);
}
