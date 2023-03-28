/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendMsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:20:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 16:32:34 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sendMsg(t_data *data, int n, char *msg)
{
	suseconds_t		start_time;
	suseconds_t		time_now;

	start_time = data->start_time;
	time_now = getTime();
	printf("%ld %d %s\n", time_now - start_time, n, msg);
}
