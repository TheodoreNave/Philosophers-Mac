/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:15:14 by tnave             #+#    #+#             */
/*   Updated: 2022/02/01 19:03:00 by tnave            ###   ########.fr       */
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

// typedef struct 	s_list_utils
// {
// 	struct s_list_utils 	*next;
// 	i;

// }				t_list_utils;

// usleep(1000000);

typedef struct 					s_utils
{
	// t_list_utils 		list;
	int							nb_philo;
	useconds_t					time_to_die;
	useconds_t					time_to_eat;
	useconds_t					time_to_sleep;
	int							each_philo_eat;

}								t_utils;

int	ft_atoi(char *str);

int	check_sign(const char *str, long int *i, int sign);

int	ft_strlen(char *str);

int	give_values_args(char **av, int i, t_utils *utils);

int	parse_arguments(char **av, t_utils *utils);

#endif