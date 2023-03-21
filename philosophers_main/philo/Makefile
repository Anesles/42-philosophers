# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:51:23 by brumarti          #+#    #+#              #
#    Updated: 2023/03/21 16:09:25 by brumarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread -I ./includes

SRC = main.c \
		srcs/philo/philo.c \
		srcs/monitor/monitor.c \
		srcs/utils/send_msg.c \
		srcs/utils/check_valid.c \
		srcs/utils/ft_atoi.c \
		srcs/utils/end_simulation.c \
		srcs/utils/get_time.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT: