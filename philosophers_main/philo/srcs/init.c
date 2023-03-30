/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:20:13 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/30 16:32:25 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    init_data(int argc, char** argv, t_data *data)
{
	data->stop = 0;
	data->NPhilos = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argc == 6)
		data-> NEat = ft_atoi(argv[5]);
	else
		data-> NEat = 0;
	if (data->ttd <= 0 || data->tte <= 0 || data->tts <= 0 || data->NPhilos < 1 || data->NEat < 0)
		return (0);
	return (1);
}

void    createMutexs(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->NPhilos)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->eat), NULL);
	pthread_mutex_init(&(data->timesEatMtx), NULL);
}

void    createPhilos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->NPhilos)
	{
		data->philos[i].timesEat = 0;
		data->philos[i].n = i + 1;
		if (i != data->NPhilos - 1)
		{	
			data->philos[i].lfork = i;
			data->philos[i].rfork = (i + 1) % data->NPhilos;
		}
		else
		{
			data->philos[i].lfork = (i + 1) % data->NPhilos;
			data->philos[i].rfork = i;
		}
		data->philos[i].data = data;
		i++;
	}
}

void    init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->NPhilos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->NPhilos);
	createMutexs(data);
	createPhilos(data);
}