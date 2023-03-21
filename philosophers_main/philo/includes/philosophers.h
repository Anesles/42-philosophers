/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:56 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/21 16:31:53 by brumarti         ###   ########.fr       */
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
	suseconds_t		start_time;
	int				start;
	int				n_philos;
	int				ttd;
	int				tte;
	int				tts;
	int				n_eat;
	pthread_mutex_t	*forks;
	t_philo 		*philos;
}	t_data;


typedef struct s_philo
{
	int		isAlive;
	int		n;
	int		ttd;
	int		tte;
	int		tts;
	int		n_eat;
	t_data	*data;
}	t_philo;

//Philo
void		*philo_main(void *info);
//Monitor
void		canEat(t_data *data, t_philo *philo);
//Utils
int			check_valid(int argc, char *argv[]);
int			ft_atoi(const char *nptr);
void		end_simulation(void);
void		send_msg(t_data *data, int n, char *msg);
suseconds_t	get_time();
#endif