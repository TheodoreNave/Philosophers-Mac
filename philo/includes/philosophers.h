/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:02:09 by tnave             #+#    #+#             */
/*   Updated: 2022/02/11 22:58:30 by tnave            ###   ########.fr       */
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

# define TAKE_LEFT_FORK "has taken a left fork"
# define TAKE_RIGHT_FORK "has taken a right fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "is dead"
typedef struct s_utils
{
	pthread_mutex_t				*forks;
	pthread_mutex_t				count_protect;
	time_t						time_to_die;
	time_t						time_to_eat;
	time_t						time_to_sleep;
	time_t						start;
	int							nb_philo;
	int							each_philo_eat;
	int 						dead;
	int							count_les_philolo;
	int 						ko;
	int 						stat;
	int 						stop_thread;
	int 						write_dead;
}								t_utils;
typedef struct s_philo
{
	pthread_mutex_t			eating;
	pthread_mutex_t			think;
	pthread_mutex_t			sleep;
	pthread_t				thread;
	pthread_t 				control;
	time_t						life_of_phi;
	t_utils					*utils;
	pthread_mutex_t 		lock;
	int						count;
	int						id;
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

int			init_forks(t_utils *utils);

#endif