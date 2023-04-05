/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:07:48 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/05 16:14:46 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_stop(t_data *data)
{
	int	state;
	
	state = 0;
	pthread_mutex_lock(&(data->print));
	if (data->stop)
		state = 1;
	pthread_mutex_unlock(&(data->print));
	return (state);
}

void	msgError(char *msg)
{
	printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}