# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnave <tnave@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 15:04:00 by tnave             #+#    #+#              #
#    Updated: 2022/02/15 17:06:44 by tnave            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =  srcs/philosophers.c							\
		srcs/utils.c								\
		srcs/threads.c								\
		srcs/parsing.c								\
		srcs/life_of_phi.c							\
		srcs/death_of_phi.c  						\
		srcs/sleep.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread -I ./includes/

HEADER = -I includes/

OBJ = $(SRCS:%.c=%.o)

ADDED = echo "\033[92m⚙️ ⚙️ ⚙️ ⚙️ ⚙️ SUCCESS\033[0m"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) && $(ADDED)

MAKEFLAGS += --silent

all: $(NAME)

%.o%.c:
	$(CC) -c $(CFLAGS) -I $(HEADER) $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re