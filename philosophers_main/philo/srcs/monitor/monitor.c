/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 16:35:15 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checkEnd(t_data *data)
{
	t_philo	*philo;
	int	ended;
	int	i;

	i = 0;
	ended = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&(data->mtxForTime));
		philo = &data->philos[i];
		if (philo->hEaten)
			ended++;
		else if ((getTime() - philo->lastAte) >= data->ttd)
		{
			sendMsg(data, philo->n, ACTION_DIED);
			data->start = 0;
			break ;
		}
		pthread_mutex_unlock(&(data->mtxForTime));
		i++;
	}
	if (ended == data->n_philos)
		data->start = 0;
}

void *monitor(void *info)
{
	t_data *data;

	data = (t_data *) info;
	while(1)
	{
		if (data->start == 1)
			break ;
	}
	while (data->start)
		checkEnd(data);
	unlockMtx(data);
	return (0);
}