/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:07:48 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/06 18:00:04 by brumarti         ###   ########.fr       */
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

void	msg_error(char *msg, t_data *data)
{
	printf("Error: %s\n", msg);
	free(data);
	exit(EXIT_FAILURE);
}
