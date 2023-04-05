/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:20:13 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/05 16:12:04 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    init_data(int argc, char** argv, t_data *data)
{
	data->stop = 0;
	data->n_philos = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argc == 6)
		data-> n_eat = ft_atoi(argv[5]);
	else
		data-> n_eat = -1;
	if (data->ttd <= 0 || data->tte <= 0 || data->tts <= 0 || data->n_philos < 1 || (argc == 6 && data->n_eat < 0))
		return (0);
	return (1);
}

void    createMutexs(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->eat), NULL);
	pthread_mutex_init(&(data->times_eat_mutex), NULL);
}

void    createPhilos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].times_eat = 0;
		data->philos[i].n = i + 1;
		data->philos[i].lfork = i;
		data->philos[i].rfork = (i + 1) % data->n_philos;
		data->philos[i].data = data;
		i++;
	}
}

void    init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	createMutexs(data);
	createPhilos(data);
}