/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:56 by brumarti          #+#    #+#             */
/*   Updated: 2023/04/06 18:00:33 by brumarti         ###   ########.fr       */
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

# define ACTION_DIED "died 💀"
# define ACTION_EATING "is eating 😋"
# define ACTION_THINKING "is thinking 🤔"
# define ACTION_SLEEPING "is sleeping 😴"
# define ACTION_FORK "has taken a fork 🍴"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	suseconds_t		start_time;
	int				stop;
	int				n_philos;
	int				ttd;
	int				tte;
	int				tts;
	int				n_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	times_eat_mutex;
	pthread_mutex_t	eat;
	t_philo			*philos;
}	t_data;

typedef struct s_philo
{
	int			times_eat;
	int			n;
	int			rfork;
	int			lfork;
	suseconds_t	last_ate;
	pthread_t	thread_id;
	t_data		*data;
}	t_philo;

//Philo
void		*philo_main(void *info);
//Start
void		start(t_data *data);
//Init
int			init_data(int argc, char**argv, t_data *data);
void		init(t_data *data);
//Utils
int			ft_atoi(const char *nptr);
void		send_msg(t_philo *philo, char *msg);
suseconds_t	get_time(void);
void		end_simulation(t_data *data);
int			check_stop(t_data *data);
void		msg_error(char *msg, t_data *data);
#endif