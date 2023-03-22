/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:34 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/22 15:08:01 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

pthread_mutex_t *create_forks(int n)
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

void	start_simulation(t_data *data)
{
	t_philo			*philos;
	pthread_t		*threads;
	int				i;

	philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philos);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * (data->n_philos + 1));
	data->forks = create_forks(data->n_philos + 1);
	i = 0;
	while(i < data->n_philos)
	{
		philos[i].isAlive = 1;
		philos[i].data = data;
		philos[i].hEat = 0;
		philos[i].lastAte = get_time();
		philos[i].n = i + 1;
		philos[i].n_eat = 0;
		pthread_create(&threads[i], NULL, philo_main, (void *) &philos[i]);
		i++;
	}
	pthread_create(&threads[i], NULL, monitor, (void *) data);
	data->ths = threads;
	data->philos = philos;
	data->start_time = get_time();
	data->start = 1;
	i = 0;
	while (i < data->n_philos + 1)
		pthread_join(threads[i++], NULL);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	
	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_data));
		data->n_philos = ft_atoi(argv[1]);
		data->ttd = ft_atoi(argv[2]);
		data->tte = ft_atoi(argv[3]);
		data->tts = ft_atoi(argv[4]);
		data->start = 0;
		if (argc == 6)
			data->n_eat = ft_atoi(argv[5]);
		else
			data->n_eat = -1;
		start_simulation(data);
	}
}
