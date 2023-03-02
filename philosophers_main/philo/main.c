/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:34 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 15:35:23 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int argc, char *argv[])
{
	struct timeval	tv;
	t_data			*data;
	
	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_data));
		data->n_philos = ft_atoi(argv[1]);
		data->ttd = ft_atoi(argv[2]);
		data->tte = ft_atoi(argv[3]);
		data->tts = ft_atoi(argv[4]);
		gettimeofday(&tv,NULL);
		data->start_time = tv.tv_usec / 1000;
		if (argc == 6)
			data->n_eat = ft_atoi(argv[5]);
		else
			data->n_eat = -1;
		start_simulation(data);
	}
}