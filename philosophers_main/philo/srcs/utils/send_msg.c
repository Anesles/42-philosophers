/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:20:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/21 16:09:48 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	send_msg(t_data *data, int n, char *msg)
{
	suseconds_t		start_time;
	suseconds_t		time_now;

	start_time = data->start_time;
	time_now = get_time();
	printf("%ld %d %s\n", time_now - start_time, n, msg);
}
