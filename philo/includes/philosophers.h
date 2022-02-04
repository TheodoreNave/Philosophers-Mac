/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:15:14 by tnave             #+#    #+#             */
/*   Updated: 2022/02/04 16:15:54 by tnave            ###   ########.fr       */
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


// usleep(1000000);

typedef struct 					s_utils
{
	time_t						time_to_die;
	time_t						time_to_eat;
	time_t						time_to_sleep;
	pthread_mutex_t 			lock;
	pthread_mutex_t 			*forks;
	int 						nb_philo;
	int							each_philo_eat;

}								t_utils;

typedef struct 	s_philo
{
	pthread_mutex_t 		*thread;
	int 					id;
	pthread_mutex_t 		eating;
	t_utils 				*utils;
}				t_philo;


void *ft_calloc(size_t size);

int	ft_atoi(char *str);

int	ft_error(char *str);

int	check_sign(const char *str, long int *i, int sign);

int	ft_strlen(char *str);

int	give_args_values(char **av, int i, t_utils *utils);

int	parse_arguments(char **av, t_utils *utils);

#endif