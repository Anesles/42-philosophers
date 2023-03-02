/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 17:43:42 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	unlockForks(t_data *data, t_philo *philo)
{
	int		i;
	t_fork	f;

	i = 0;
	while (i < data->n_philos)
	{
		f = data->forks[i];
		if (f.n == philo->n)
		{
			pthread_mutex_unlock(&f.lock);
			if (f.owner != philo->n)
			{
				f.n = f.owner;
				send_msg(data, f.owner, "has taken a fork");
			}
		}
	}
}

void	*philo_main(void *info)
{
	t_philo	*philo;
	
	philo = (t_philo *) info;
	printf("Created philo %d with ttd %d; tte %d; tts %d\n", philo->n, philo->ttd, philo->tte, philo->tts);
	printf("%d\n", philo->ttd);
	while(philo->isAlive)
	{
		if (philo->tte <= 0)
		{
			unlockForks(philo->data, philo);
			philo->ttd = philo->data->ttd;
			philo->tte = philo->data->tte;
			philo->eat = 0;
			send_msg(philo->data, philo->n, "is sleeping");
			philo->sle = 1;
		}
		else if (philo->tts <= 0)
		{
			philo->sle = 0;
			philo->tts = philo->data->tts;
			philo->wEat = 1;
			send_msg(philo->data, philo->n, "is thinking");
		}
		if (philo->ttd <= 0)
			philo->isAlive = 0;
		if (philo->eat)
			philo->tte--;
		if(philo->sle)
			philo->tts--;
		philo->ttd--;
		usleep(1000);
	}
	send_msg(philo->data, philo->n, "died");
	return (NULL);
}