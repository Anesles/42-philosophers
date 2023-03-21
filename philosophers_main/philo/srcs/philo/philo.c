/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/21 16:34:17 by brumarti         ###   ########.fr       */
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
	while(philo->isAlive)
	{
		canEat(philo->data, philo);
		philo->n_eat++;
		usleep(philo->data->tts);
		send_msg(philo->data, philo->n, "is thinking.");
		if (philo->n_eat == philo->data->n_eat)
			break ;
	}
	send_msg(philo->data, philo->n, "died");
	return (NULL);
}