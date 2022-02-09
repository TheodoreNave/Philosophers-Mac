# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnave <tnave@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 17:14:41 by tnave             #+#    #+#              #
#    Updated: 2022/02/09 18:08:32 by tnave            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =  srcs/philo.c								\
		srcs/utils.c								\
		srcs/utils_two.c							\
		srcs/parsing.c 								\
		srcs/print.c

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