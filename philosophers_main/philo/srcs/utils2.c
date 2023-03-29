/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:07:48 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/29 18:23:11 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	checkmaxAte(t_data *data)
{
	int	state;
	
	state = 0;
	pthread_mutex_lock(&(data->print));
	if (data->maxAte)
		state = 1;
	pthread_mutex_unlock(&(data->print));
	return (state);
}

int	checkStop(t_data *data)
{
	int	state;
	
	state = 0;
	pthread_mutex_lock(&(data->print));
	if (data->stop)
		state = 1;
	pthread_mutex_unlock(&(data->print));
	return (state);
}