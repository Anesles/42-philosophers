/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 16:10:43 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*monitor(void *info)
{
	t_data *data = (t_data *) info;
	(void) data;
	printf("Created monitor\n");
	while (1)
	{
		usleep(5000);
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	t_philo			*philos;
	pthread_t		*threads;
	int				i;

	philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (data->n_philos + 1));
	i = 0;
	while(i < 5)
	{
		philos[i].isAlive = 1;
		philos[i].data = data;
		philos[i].forks = malloc(sizeof(t_fork) * 2);
		philos[i].n = i + 1;
		philos[i].ttd = data->ttd;
		philos[i].tte = data->tte;
		philos[i].tts = data->tts;
		pthread_create(&threads[i], NULL, philo_main, (void *) &philos[i]);
		i++;
	}
	data->philos = philos;
	pthread_create(&threads[i], NULL, monitor, (void *) data);
	i = 0;
	while (i < 6)
		pthread_join(threads[i], NULL);
}