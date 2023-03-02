/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:56 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 16:12:21 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo t_philo;

typedef struct s_data
{
	long int	start_time;
	int			n_philos;
	int			ttd;
	int			tte;
	int			tts;
	int			n_eat;
	t_philo 	*philos;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mt;
}	t_fork;

typedef struct s_philo
{
	int		isAlive;
	int		n;
	int		ttd;
	int		tte;
	int		tts;
	t_fork	*forks;
	t_data	*data;
}	t_philo;

//Philo
void	*philo_main(void *info);
//Monitor
void	start_simulation(t_data *data);
//Utils
int		check_valid(int argc, char *argv[]);
int		ft_atoi(const char *nptr);
void	end_simulation(void);
t_philo	copy_philo(int n, t_philo philo);
#endif