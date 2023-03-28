/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_continue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:20:39 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 15:21:01 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_continue(t_data *data)
{
	pthread_mutex_t	lock;
	int	state;

	state = 0;
	lock = data->mtxDataRace;
	pthread_mutex_lock(&lock);
	if (data->start == 0)
		state = 1;
	pthread_mutex_unlock(&lock);	
	return (state);
}