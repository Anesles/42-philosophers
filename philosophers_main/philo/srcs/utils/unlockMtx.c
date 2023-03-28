/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlockMtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:21:37 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 15:21:49 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	unlockMtx(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
		pthread_mutex_unlock(&(data->forks[i++]));
	pthread_mutex_unlock(&data->mtxDataRace);
	pthread_mutex_unlock(&data->mtxForTime);
}