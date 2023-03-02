/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 16:13:20 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*philo_main(void *info)
{
	struct timeval	tv;
	t_fork			fork;
	long int		start_time;
	pthread_mutex_t	mt_fork;
	
	pthread_mutex_init(&mt_fork, NULL);
	fork.mt = mt_fork;
	t_philo *philo = (t_philo *) info;
	philo->forks[0] = fork;
	printf("Created philo %d with ttd %d; tte %d; tts %d\n", philo->n, philo->ttd, philo->tte, philo->tts);
	while(philo->isAlive)
	{
		philo->ttd--;
		if (philo->ttd <= 0)
			philo->isAlive = 0;
		usleep(1000);
	}
	gettimeofday(&tv, NULL);
	start_time = philo->data->start_time;
	printf("%ld %d died\n", ((tv.tv_usec / 1000) - start_time), philo->n);
	return (NULL);
}