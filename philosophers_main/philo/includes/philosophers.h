/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:56 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/02 17:25:53 by brumarti         ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				n;
	int				owner;
}	t_fork;

typedef struct s_data
{
	long int	start_time;
	int			n_philos;
	int			ttd;
	int			tte;
	int			tts;
	int			n_eat;
	t_fork		*forks;
	t_philo 	*philos;
}	t_data;


typedef struct s_philo
{
	int		isAlive;
	int		wEat;
	int		eat;
	int		sle;
	int		n;
	int		ttd;
	int		tte;
	int		tts;
	t_data	*data;
}	t_philo;

//Philo
void	*philo_main(void *info);
//Monitor
void	*monitor(void *info);
//Utils
int		check_valid(int argc, char *argv[]);
int		ft_atoi(const char *nptr);
void	end_simulation(void);
void	send_msg(t_data *data, int n, char *msg);
#endif