/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:02:09 by tnave             #+#    #+#             */
/*   Updated: 2022/02/15 15:56:03 by tnave            ###   ########.fr       */
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

# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_utils
{
	pthread_mutex_t				*forks;
	pthread_mutex_t				count_protect;
	pthread_mutex_t				lock;
	pthread_mutex_t				is_dead;
	time_t						time_to_die;
	time_t						time_to_eat;
	time_t						time_to_sleep;
	time_t						start;
	int							nb_philo;
	int							each_philo_eat;
	int							dead;
	int							write_dead;
}								t_utils;
typedef struct s_philo
{
	pthread_mutex_t			eating;
	pthread_t				thread;
	pthread_t				control;
	time_t					life_of_phi;
	t_utils					*utils;
	int						count;
	int						id;
}							t_philo;

int		parse_arguments(char **av, t_utils *utils);

int		give_args_values(char **av, int i, t_utils *utils);

int		check_sign(const char *str, long int *i, int sign);

int		ft_atoi(char *str);

int		join_thread(t_philo *philo, t_utils *utils);

void	check_dead_philo(t_philo *philo);

void	morning_routine(t_philo *philo);		// cast en * ?

int		philosophers(t_philo *philo, t_utils *utils);

int		one_philo(t_philo *philo, char **av);

int		init_forks(t_utils *utils);

void	snooze(time_t t);

time_t	get_time(time_t start);

int		ft_error(char *str);

int		free_all(t_philo *philo, t_utils *utils, int error);

int		setup_count_and_life(t_philo *phi);

void	write_thread(char *str, time_t time, t_philo *philo, char *define);

t_philo	*call_philos(t_utils *utils);

void	*ft_calloc(int size);

int		ft_strlen(char *str);

int		philo_impair(t_philo *philo, t_utils *utils);

int		philo_pair(t_philo *philo, t_utils *utils);

#endif