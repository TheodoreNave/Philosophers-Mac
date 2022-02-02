/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:15:14 by tnave             #+#    #+#             */
/*   Updated: 2022/02/02 11:22:19 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>

typedef struct 	s_philo
{
	struct s_philo 	*next;
	int 			philo;
	int 			forks;

}				t_philo;

// usleep(1000000);

typedef struct 					s_utils
{
	int							nb_philo;
	__useconds_t				time_to_die;
	__useconds_t				time_to_eat;
	__useconds_t				time_to_sleep;
	t_philo 					philo;
	int							each_philo_eat;

}								t_utils;

int	ft_atoi(char *str);

int	check_sign(const char *str, long int *i, int sign);

int	ft_strlen(char *str);

int	give_args_values(char **av, int i, t_utils *utils);

int	parse_arguments(char **av, t_utils *utils);

#endif