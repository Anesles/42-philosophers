/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:34 by brumarti          #+#    #+#             */
/*   Updated: 2023/01/25 17:57:39 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int argc, char *argv[])
{
	int	n;
	int	tts;
	int	ttd;
	int	tte;
	t_philo	*philos;
	
	if ((argc == 5) && check_valid(argc, argv))
	{
		n = ft_atoi(argv[1]);
		philos = malloc(sizeof(t_philo) * n);
		ttd = ft_atoi(argv[2]);
		tte = ft_atoi(argv[3]);
		tts = ft_atoi(argv[4]);
		create_philo(philos, n, ttd, tte, tts);
	}
}