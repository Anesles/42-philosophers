/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:05:09 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/21 16:06:39 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

suseconds_t	getTime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}