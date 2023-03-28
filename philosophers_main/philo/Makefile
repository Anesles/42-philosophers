# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:51:23 by brumarti          #+#    #+#              #
#    Updated: 2023/03/28 18:05:39 by brumarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread -I ./includes

SRC = main.c \
		srcs/philo/philo.c \
		srcs/monitor/monitor.c \
		srcs/utils/sendMsg.c \
		srcs/utils/checkValid.c \
		srcs/utils/ft_atoi.c \
		srcs/utils/endSimulation.c \
		srcs/utils/getTime.c \
		srcs/utils/unlockMtx.c \
		srcs/utils/checkContinue.c

OBJ = $(SRC:.c=.o)

#Execute Params
NPHILOS = 5
TTD = 200
TTE = 50
TTS = 50
NEAT = 10
RESULT = $(shell echo $$(($(NPHILOS) * $(NEAT))))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	echo "Executing program with $(NPHILOS) philos with:\nTime to Die = $(TTD) miliseconds;\nTime to Eat = $(TTE) miliseconds;\nTime to Sleep = $(TTS) miliseconds;\nNumber of times to eat = $(NEAT) times."
	echo "If the number printed is $(RESULT) than its correct !"
	./philo $(NPHILOS) $(TTD) $(TTE) $(TTS) $(NEAT) | grep -c "is eating"

.SILENT: