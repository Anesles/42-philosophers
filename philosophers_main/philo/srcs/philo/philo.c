/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/22 17:44:02 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_main(void *info)
{
	t_philo	*philo;
	
	philo = (t_philo *) info;
	while(1)
		if (philo->data->start == 1)
			break ;
	while(philo->data->start)
	{
		if (philo->n_eat != philo->data->n_eat)
		{
			canEat(philo->data, philo);
			philo->n_eat++;
			usleep(philo->data->tts * 1000);
			send_msg(philo->data, philo->n, ACTION_THINKING);
		}
		else
		{
			philo->hEat = 1;
			break ;
		}
	}
	printf("Philo %d ended !\n", philo->n);
	return (NULL);
}