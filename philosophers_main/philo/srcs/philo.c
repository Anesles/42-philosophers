/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/30 17:11:15 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkNEat(t_data *data, int n)
{
	int	state;

	state = 0;
	if (n != data-> NEat)
		state = 1;
	return (state);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->lfork]));
	sendMsg(philo, ACTION_FORK);
	pthread_mutex_lock(&(philo->data->forks[philo->rfork]));
	sendMsg(philo, ACTION_FORK);
	pthread_mutex_lock(&(philo->data->eat));
	sendMsg(philo, ACTION_EATING);
	philo->lastAte = getTime();
	pthread_mutex_unlock(&(philo->data->eat));
	usleep(philo->data->tte * 1000);
	pthread_mutex_lock(&(philo->data->timesEatMtx));
	philo->timesEat++;
	pthread_mutex_unlock(&(philo->data->timesEatMtx));
	pthread_mutex_unlock(&(philo->data->forks[philo->lfork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->rfork]));
}

void	*philoMain(void *info)
{
	t_philo	*philo;
	t_data	*data;
	
	philo = (t_philo *) info;
	data = philo->data;
	if (philo->n % 2)
		usleep(200);
	while(!checkStop(data) && checkNEat(data, philo->timesEat))
	{
		if (philo->data->NPhilos != 1)
		{
			eating(philo);
			sendMsg(philo, ACTION_SLEEPING);
			usleep(data->tts * 1000);
			sendMsg(philo, ACTION_THINKING);
		}
	}
	return (NULL);
}