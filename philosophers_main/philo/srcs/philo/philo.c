/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:18:26 by brumarti          #+#    #+#             */
/*   Updated: 2023/01/25 18:06:28 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*handle_philo(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	
	printf("Created Philosopher with id %d, %d ttd, %d tte, %d tts and tdi %ld.\n", philo->n, philo->ttd, philo->tte, philo->tts, *philo->tid);
	return (NULL);
}

void	create_philo(t_philo *philos, int n, int ttd, int tte, int tts)
{
	pthread_t	*tids;
	int	i;

	tids = malloc(sizeof(pthread_t) * n);
	i = 0;
	while (i < n)
	{
		philos[i].tid = &tids[i];
		philos[i].n = i + 1;
		philos[i].ttd = ttd;
		philos[i].tte = tte;
		philos[i].tts = tts;
		pthread_create(&tids[i], NULL, handle_philo, &philos[i]);
		i++;
	}
	pthread_join(tids[0], NULL);
	pthread_join(tids[1], NULL);
	pthread_join(tids[2], NULL);
	pthread_join(tids[3], NULL);
	pthread_join(tids[4], NULL);
}