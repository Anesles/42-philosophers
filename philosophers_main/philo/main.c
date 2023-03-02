/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:34 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 17:37:18 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

t_fork *create_forks(int n)
{
	int	i;
	t_fork *forks;
	pthread_mutex_t *mutexs;
	
	forks = malloc(sizeof(t_fork) * n);
	mutexs = malloc(sizeof(pthread_mutex_t) * n);
	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&mutexs[i], NULL);
		forks[i].lock = mutexs[i];
		forks[i].n = i + 1;
		forks[i].owner = i + 1;
		i++;
	}
	return (forks);
}

void	start_simulation(t_data *data)
{
	t_philo			*philos;
	pthread_t		*threads;
	int				i;

	philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (data->n_philos + 1));
	data->forks = create_forks(data->n_philos);
	i = 0;
	while(i < 5)
	{
		philos[i].isAlive = 1;
		philos[i].data = data;
		philos[i].wEat = 1;
		philos[i].eat = 0;
		philos[i].n = i + 1;
		philos[i].ttd = data->ttd;
		philos[i].tte = data->tte;
		philos[i].tts = data->tts;
		pthread_create(&threads[i], NULL, philo_main, (void *) &philos[i]);
		i++;
	}
	usleep(5000);
	data->philos = philos;
	pthread_create(&threads[i], NULL, monitor, (void *) data);
	i = 0;
	while (i < 6)
		pthread_join(threads[i], NULL);
}

int	main(int argc, char *argv[])
{
	struct timeval	tv;
	t_data			*data;
	
	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_data));
		data->n_philos = ft_atoi(argv[1]);
		data->ttd = ft_atoi(argv[2]);
		data->tte = ft_atoi(argv[3]);
		data->tts = ft_atoi(argv[4]);
		gettimeofday(&tv,NULL);
		data->start_time = tv.tv_usec / 1000;
		if (argc == 6)
			data->n_eat = ft_atoi(argv[5]);
		else
			data->n_eat = -1;
		start_simulation(data);
	}
}
