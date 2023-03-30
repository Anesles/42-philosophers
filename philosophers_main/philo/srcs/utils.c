/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:29:31 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/30 15:52:05 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		count_minus;
	int		n;

	str = (char *)nptr;
	count_minus = 1;
	n = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 14))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count_minus = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	return (n * count_minus);
}

suseconds_t	getTime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sendMsg(t_philo *philo, char *msg)
{
	suseconds_t	timestamp;

	timestamp = getTime() - philo->data->start_time;
	pthread_mutex_lock(&(philo->data->print));
	if (!philo->data->stop)
		printf("%ld %d %s\n", timestamp, philo->n, msg);
	pthread_mutex_unlock(&(philo->data->print));
}

void    endSimulation(t_data *data)
{
	int	i;
	
	if (data->NPhilos == 1)
		pthread_detach(data->philos[0].threadID);
	else
	{
		i = 0;
		while (i < data->NPhilos)
		{
			pthread_join(data->philos[i].threadID, NULL);
			i++;
		}
	}
	i = 0;
	while (i < data->NPhilos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->eat);
	pthread_mutex_destroy(&data->print);
	free(data->philos);
	free(data->forks);
}