/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/01 18:05:04 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*philo_main(void *info)
{
	t_philo *philo = (t_philo *) info;
	printf("Created philo %d with ttd %d; tte %d; tts %d\n", philo->n, philo->ttd, philo->tte, philo->tts);
	while(1)
	{
		usleep(5000);
	}
	return (NULL);
}

t_philo	*create_philo(int n, t_data *data)
{
	t_philo		*philo;
	pthread_t	thread;
	
	philo = malloc(sizeof(t_philo)); 
	philo->n = n;
	philo->data = data;
	philo->ttd = data->ttd;
	philo->tte = data->tte;
	philo->tts = data->tts;
	pthread_create(&thread, NULL, philo_main, (void *) philo);
	return(philo);
}