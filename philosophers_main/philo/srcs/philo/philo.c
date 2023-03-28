/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 18:08:11 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkNEat(t_data *data, int n)
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

void	lockForks(t_data *data, int n)
{
	if (n == data->n_philos)
	{
		pthread_mutex_lock(&(data->forks[0]));
		pthread_mutex_lock(&(data->forks[data->n_philos - 1]));
	}
	else
	{	
		pthread_mutex_lock(&(data->forks[n - 1]));
		pthread_mutex_lock(&(data->forks[n % data->n_philos]));
	}
	sendMsg(data, n, ACTION_FORK);
	sendMsg(data, n, ACTION_FORK);
}

void	eating(t_data *data, t_philo *philo)
{
	if (checkContinue(data))
		return ;
	lockForks(data, philo->n);
	if (checkContinue(data))
		return ;
	sendMsg(data, philo->n, ACTION_EATING);
	usleep(data->tte * 1000);
	if (checkContinue(data))
		return ;
	pthread_mutex_lock(&(data->mtxForTime));
	if (checkContinue(data))
		return ;
	philo->lastAte = getTime();
	pthread_mutex_unlock(&(data->mtxForTime));
	pthread_mutex_unlock(&(data->forks[philo->n - 1]));
	pthread_mutex_unlock(&(data->forks[philo->n % data->n_philos]));
	sendMsg(data, philo->n, ACTION_SLEEPING);
}

int	canEat(t_data *data, int n)
{
	int	i;
	
	if (data->init == 1)
	{
		i = 1;
		while (i < data->n_philos)
		{
			if (n == i)
				return (1);
			i += 3;
		}
	}
	else
		return (1);
	data->init = 0;
	return (0);
}

void	*philoMain(void *info)
{
	t_philo			*philo;
	
	philo = (t_philo *) info;
	while(1)
	{
		if (!checkContinue(philo->data))
			break;
	}
	while(philo->data->start)
	{
		if (checkNEat(philo->data, philo->n_eat))
		{
			if(!canEat(philo->data, philo->n))
				usleep(500);
			eating(philo->data, philo);
			if (checkContinue(philo->data))
				break;
			philo->n_eat++;
			usleep(philo->data->tts * 1000);
			if (checkContinue(philo->data))
				break;
			sendMsg(philo->data, philo->n, ACTION_THINKING);
		}
		else
		{
			philo->hEaten = 1;
			break ;
		}
	}
	//printf("Philo %d has ended\n", philo->n);
	return (NULL);
}