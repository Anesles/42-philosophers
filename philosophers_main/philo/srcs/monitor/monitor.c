/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:52 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 17:42:33 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	canEat(t_data *data, t_philo *philo)
{
	t_fork			f1;
	t_fork			f2;
	
	f1 = data->forks[philo->n - 1];
	if (f1.n == philo->n)
	{
		pthread_mutex_lock(&f1.lock);
		if (philo->n == data->n_philos)
			f2 = data->forks[0];
		else
			f2 = data->forks[philo->n];
		if (f2.n == (philo->n + 1))
		{
			pthread_mutex_lock(&f2.lock);
			f2.n = philo->n;
			send_msg(data, philo->n, "has taken a fork");
			philo->eat = 1;
			send_msg(data, philo->n, "is eating");
			return (1);
		}
	}
	return (0);
}

void	*monitor(void *info)
{
	int	i;
	t_philo *philo;
	t_data *data;

	data = (t_data *) info;
	printf("Created monitor\n");
	i = 0;
	while (1)
	{
		if (i == data->n_philos)
			i = 0;
		philo = &data->philos[i];
		if (philo->wEat && canEat(data, philo))
			philo->wEat = 0;
		usleep(1000);
		i++;
	}
	return (NULL);
}
