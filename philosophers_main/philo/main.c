/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:34 by brumarti          #+#    #+#             */
/*   Updated: 2023/03/29 17:52:30 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	checkValid(int	argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (argc < 5 || argc > 6)
		printf("Error");
	if (!checkValid(argc, argv))
		printf("Error");
	else if (!init_data(argc, argv, data))
		printf("Error");
	init(data);
	start(data);
}
