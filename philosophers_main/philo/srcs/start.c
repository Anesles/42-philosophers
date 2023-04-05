/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:51 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/05 18:15:35 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	finished_eating(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&(data->times_eat_mutex));
	while (i < data->n_philos)
	{
		if (data->philos[i].times_eat == data->n_eat)
			count++;
		i++;
	}
	pthread_mutex_unlock(&(data->times_eat_mutex));
	if (count == data->n_philos)
		return (1);
	return (0);
}

void	died(t_data *data, int i)
{
	pthread_mutex_unlock(&data->eat);
	send_msg(&(data->philos[i]), ACTION_DIED);
	pthread_mutex_lock(&data->print);
	data->stop = 1;
	pthread_mutex_unlock(&data->print);
}

void	check_end(t_data *data)
{
	int	i;

	while (!check_stop(data) && !finished_eating(data))
	{
		i = -1;
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&data->eat);
			if ((get_time() - data->philos[i].last_ate) >= data->ttd)
			{
				died(data, i);
				break ;
			}
			pthread_mutex_unlock(&data->eat);
		}
		pthread_mutex_lock(&data->print);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->print);
			break ;
		}
		pthread_mutex_unlock(&data->print);
	}
}

void	start(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	data->start_time = get_time();
	while (i < data->n_philos)
	{
		philo = &(data->philos[i]);
		data->philos[i].last_ate = get_time();
		pthread_create(&(philo->thread_id), NULL, philo_main, philo);
		i++;
	}
	check_end(data);
	end_simulation(data);
}
