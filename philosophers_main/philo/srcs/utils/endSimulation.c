/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endSimulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:07:58 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 15:09:00 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy(pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

void	endSimulation(t_data *data)
{
	unlockMtx(data);
	destroy(data->forks, data->n_philos);
	free(data->philos);
	free(data->ths);
	free(data);
	exit(EXIT_FAILURE);
}
