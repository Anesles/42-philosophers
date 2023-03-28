/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:34 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 18:06:37 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

pthread_mutex_t *createForks(int n)
{
	int	i;
	pthread_mutex_t	*forks;
	
	forks = malloc(sizeof(pthread_mutex_t) * n);
	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	startSimulation(t_data *data)
{
	t_philo			*philos;
	pthread_t		*threads;
	int				i;

	philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (data->n_philos + 1));
	data->forks = createForks(data->n_philos);
	i = 0;
	while(i < data->n_philos)
	{
		philos[i].isAlive = 1;
		philos[i].data = data;
		philos[i].hEaten = 0;
		philos[i].lastAte = getTime();
		philos[i].n = i + 1;
		philos[i].n_eat = 0;
		pthread_create(&threads[i], NULL, philoMain, (void *) &philos[i]);
		i++;
	}
	pthread_create(&threads[i], NULL, monitor, (void *) data);
	data->ths = threads;
	data->philos = philos;
	data->start_time = getTime();
	data->start = 1;
	i = 0;
	while (i < data->n_philos + 1)
		pthread_join(threads[i++], NULL);
	endSimulation(data);
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	mtxT;
	pthread_mutex_t	mtxD;
	t_data	*data;
	
	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_data));
		pthread_mutex_init(&mtxT, NULL);
		pthread_mutex_init(&mtxD, NULL);
		data->mtxForTime = mtxT;
		data->init = 1;
		data->mtxDataRace = mtxD;
		data->n_philos = ft_atoi(argv[1]);
		data->ttd = ft_atoi(argv[2]);
		data->tte = ft_atoi(argv[3]);
		data->tts = ft_atoi(argv[4]);
		data->start = 0;
		if (argc == 6)
			data->n_eat = ft_atoi(argv[5]);
		else
			data->n_eat = -1;
		startSimulation(data);
	}
}
