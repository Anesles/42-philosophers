/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:59 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/21 15:39:26 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_main(void *info)
{
	t_philo	*philo;
	
	philo = (t_philo *) info;
	printf("Created philo %d with ttd %d; tte %d; tts %d\n", philo->n, philo->ttd, philo->tte, philo->tts);
	printf("%d\n", philo->ttd);
	while(philo->isAlive)
	{
		canEat(philo->data, philo);
		usleep(philo->data->tts);
		send_msg(philo->data, philo->n, "is thinking.");
	}
	send_msg(philo->data, philo->n, "died");
	return (NULL);
}