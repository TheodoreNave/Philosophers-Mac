/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:02:09 by tnave             #+#    #+#             */
/*   Updated: 2022/02/09 18:03:49 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>

// # define TAKE_FORK
// # define EAT
// # define SLEEP
// # define THINK
typedef struct s_utils
{
	time_t						time_to_die;
	time_t						time_to_eat;
	time_t						time_to_sleep;
	time_t						start;
	pthread_mutex_t				lock;
	pthread_mutex_t				*forks;
	int							nb_philo;
	int							each_philo_eat;
	int							count;
}								t_utils;
typedef struct s_philo
{
	int						id;
	pthread_mutex_t			eating;
	pthread_mutex_t			think;
	pthread_mutex_t			sleep;
	t_utils					*utils;
	pthread_t				thread;
}							t_philo;

void		snooze(time_t t);

time_t		get_time(time_t start);

void		*ft_calloc(int size);

int			ft_atoi(char *str);

int			ft_error(char *str);

int			check_sign(const char *str, long int *i, int sign);

int			ft_strlen(char *str);

int			give_args_values(char **av, int i, t_utils *utils);

int			parse_arguments(char **av, t_utils *utils);

void		routine(t_philo *philo);

t_philo		*call_philos(t_utils *utils);

void		philosophers(t_philo *philo, t_utils *utils);

void		print_values(t_utils *utils);

int			philo_die(t_philo *philo);

int			one_philo(t_philo *philo, char **av);

void		init_forks(t_utils *utils);

#endif