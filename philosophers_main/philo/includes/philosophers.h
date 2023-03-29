/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:56 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/29 18:08:58 by brumarti         ###   ########.fr       */
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
	int				stop;
	int				NPhilos;
	int				ttd;
	int				tte;
	int				tts;
	int				NEat;
	int				maxAte;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	t_philo 		*philos;
}	t_data;

typedef struct s_philo
{
	int			timesEat;
	int			n;
	int			rfork;
	int			lfork;
	suseconds_t	lastAte;
	pthread_t	threadID;
	t_data		*data;
}	t_philo;

//Philo
void		*philoMain(void *info);
//Start
void		start(t_data *data);
//Init
int			init_data(int argc, char** argv, t_data *data);
void		init(t_data *data);
//Utils
int			ft_atoi(const char *nptr);
void		sendMsg(t_philo *philo, char *msg);
suseconds_t	getTime();
void		endSimulation(t_data *data);
int			checkmaxAte(t_data *data);
int			checkStop(t_data *data);
#endif