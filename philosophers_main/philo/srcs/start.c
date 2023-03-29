/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:51 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/29 18:28:38 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checkEnd(t_data *data)
{
	int	i;

	while (!checkmaxAte(data) && !checkStop(data))
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
			}
			pthread_mutex_unlock(&data->eat);
			i++;
		}
		pthread_mutex_lock(&data->print);
		if (data->stop)
			break ;
		i = 0;
		while(i < data->NPhilos && data->philos[i].timesEat >= data->NEat)
			i++;
		data->maxAte = (i == data->NPhilos);
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