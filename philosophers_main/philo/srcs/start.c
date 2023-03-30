/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:51 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/30 16:33:23 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	finishedEating(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&(data->timesEatMtx));
	while (i < data->NPhilos)
	{
		if (data->philos[i].timesEat == data->NEat)
			count++;
		i++;
	}
	pthread_mutex_unlock(&(data->timesEatMtx));
	if (count == data->NPhilos)
		return (1);
	return (0);
}

void	checkEnd(t_data *data)
{
	int	i;

	while (!checkStop(data) && !finishedEating(data))
	{
		i = 0;
		while (i < data->NPhilos)
		{
			pthread_mutex_lock(&data->eat);
			if ((getTime() - data->philos[i].lastAte) >= data->ttd)
			{
				sendMsg(&(data->philos[i]), ACTION_DIED);
				pthread_mutex_lock(&data->print);
				data->stop = 1;
				pthread_mutex_unlock(&data->print);
				pthread_mutex_unlock(&data->eat);
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
	while (i < data->NPhilos)
	{
		data->philos[i].lastAte = getTime();
		pthread_create(&(data->philos[i].threadID), NULL, philoMain, &(data->philos[i]));
		i++;
	}
	checkEnd(data);
	endSimulation(data);
}