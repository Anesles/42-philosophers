/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:56 by brumarti          #+#    #+#             */
/*   Updated: 2023/02/07 17:15:29 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t	*tid;
	int			n;
	int			ttd;
	int			tte;
	int			tts;
	int			ta;
}	t_philo;

//Philo
void	create_philo(t_philo *philos, int n, int ttd, int tte, int tts);
//Monitor
void	monitor(void);
//Utils
int		check_valid(int argc, char *argv[]);
int		ft_atoi(const char *nptr);
void	end_simulation(void);
#endif