/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/21 15:48:31 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void canEat(t_data *data, t_philo *philo)
{
	pthread_mutex_t	f1;
	pthread_mutex_t	f2;
	
	f1 = data->forks[philo->n - 1];
	f2 = data->forks[philo->n % philo->data->n_philos];
	pthread_mutex_lock(&f1);
	pthread_mutex_lock(&f2);
	send_msg(data, philo->n, "has taken fork.");
	send_msg(data, philo->n, "has taken fork.");
	send_msg(data, philo->n, "started eating.");
	usleep(data->tte);
	pthread_mutex_unlock(&f1);
	pthread_mutex_unlock(&f2);
	send_msg(data, philo->n, "is sleeping.");
}
