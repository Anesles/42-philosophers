/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/21 16:35:03 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void canEat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->n - 1]));
	pthread_mutex_lock(&(data->forks[philo->n % philo->data->n_philos]));
	//printf("%d has taken fork %d, and %d\n",philo->n, philo->n - 1, philo->n % philo->data->n_philos);
	send_msg(data, philo->n, "has taken fork.");
	send_msg(data, philo->n, "has taken fork.");
	send_msg(data, philo->n, "started eating.");
	usleep(data->tte);
	pthread_mutex_unlock(&(data->forks[philo->n - 1]));
	pthread_mutex_unlock(&(data->forks[philo->n % philo->data->n_philos]));
	send_msg(data, philo->n, "is sleeping.");
}
