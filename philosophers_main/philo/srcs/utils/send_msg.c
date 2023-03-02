/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:20:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 17:35:40 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	send_msg(t_data *data, int n, char *msg)
{
	struct timeval	tv;
	long int		start_time;

	start_time = data->start_time;
	gettimeofday(&tv, NULL);
	printf("%ld %d %s\n", (tv.tv_usec / 1000) - start_time, n, msg);
}
