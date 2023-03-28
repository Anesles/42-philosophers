/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:56 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/28 16:22:45 by brumarti         ###   ########.fr       */
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

# define ACTION_DIED "died"
# define ACTION_EATING "is eating"
# define ACTION_THINKING "is thinking"
# define ACTION_SLEEPING "is sleeping"
# define ACTION_FORK "has taken a fork"

typedef struct s_philo t_philo;

typedef struct s_data
{
	suseconds_t		start_time;
	int				start;
	int				n_philos;
	int				ttd;
	int				tte;
	int				tts;
	int				n_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mtxForTime;
	pthread_mutex_t mtxDataRace;
	pthread_t		*ths;
	t_philo 		*philos;
}	t_data;

typedef struct s_philo
{
	int				isAlive;
	int				hEaten;
	int				n;
	suseconds_t		lastAte;
	int				n_eat;
	t_data			*data;
}	t_philo;

//Philo
void		*philo_main(void *info);
//Monitor
void		*monitor(void *info);
//Utils
int			check_valid(int argc, char *argv[]);
int			check_continue(t_data *data);
void		unlock_mtx(t_data *data);
int			ft_atoi(const char *nptr);
void		end_simulation(t_data *data);
void		send_msg(t_data *data, int n, char *msg);
suseconds_t	get_time();
#endif