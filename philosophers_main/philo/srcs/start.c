/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:51 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/05 16:14:46 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	finishedEating(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&(data->times_eat_mutex));
	while (i < data->n_philos)
	{
		if (data->philos[i].times_eat == data->n_eat)
			count++;
		i++;
	}
	pthread_mutex_unlock(&(data->times_eat_mutex));
	if (count == data->n_philos)
		return (1);
	return (0);
}

void	checkEnd(t_data *data)
{
	int	i;

	while (!check_stop(data) && !finishedEating(data))
	{
		i = 0;
		while (i < data->n_philos)
		{
			pthread_mutex_lock(&data->eat);
			if ((getTime() - data->philos[i].last_ate) >= data->ttd)
			{
				pthread_mutex_unlock(&data->eat);
				sendMsg(&(data->philos[i]), ACTION_DIED);
				pthread_mutex_lock(&data->print);
				data->stop = 1;
				pthread_mutex_unlock(&data->print);
				break ;
			}
			pthread_mutex_unlock(&data->eat);
			i++;
		}
		pthread_mutex_lock(&data->print);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->print);
			break ;
		}
		pthread_mutex_unlock(&data->print);
	}
}

void    start(t_data *data)
{
	int i;

	i = 0;
	data->start_time = getTime();
	while (i < data->n_philos)
	{
		data->philos[i].last_ate = getTime();
		pthread_create(&(data->philos[i].thread_id), NULL, philoMain, &(data->philos[i]));
		i++;
	}
	checkEnd(data);
	endSimulation(data);
}