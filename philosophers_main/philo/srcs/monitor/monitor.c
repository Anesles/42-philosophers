/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/01 18:09:08 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*monitor(void *info)
{
	t_data *data = (t_data *) info;
	(void) data;
	printf("Created monitor\n");
	while (1)
	{
		usleep(5000);
	}
	return (NULL);
}

void start_simulation(t_data *data)
{
	int	i;
	pthread_t	thread;
	struct timeval tv;
	
	i = 1;
	while (i <= 5)
	{
		data->philos[i - 1] = create_philo(i, data);
		i++;
	}
	gettimeofday(&tv,NULL);
	data->start_time = tv.tv_sec;
	pthread_create(&thread, NULL, monitor, (void *) data);
	pthread_join(thread, NULL);
}