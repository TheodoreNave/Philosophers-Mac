/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:14:49 by tnave             #+#    #+#             */
/*   Updated: 2022/02/09 18:08:01 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*call_philos(t_utils *utils)
{
	int			nb_philo;
	int			i;
	t_philo		*philo;

	nb_philo = utils->nb_philo;
	i = 0;
	philo = ft_calloc(sizeof(t_philo) * nb_philo);
	while (i < nb_philo)
	{
		philo[i].id = i;
		philo[i].utils = utils;
		pthread_mutex_init(&philo[i].eating, NULL);
		i++;
	}
	return (philo);
}

void	routine(t_philo *philo)
{
	t_philo *phi;

	// int count = 0;
	phi = (t_philo *)philo;
	// if (phi->utils->each_philo_eat > -1)
	// {
		// count = phi->utils->each_philo_eat;
		while (1)
		{
			pthread_mutex_lock(&phi->utils->forks[phi->id]);
			pthread_mutex_lock(&phi->utils->lock);
			printf("%ld %d has taken a left fork\n", get_time(phi->utils->start), phi->id + 1);
			pthread_mutex_unlock(&phi->utils->lock);
			pthread_mutex_lock(&phi->utils->forks[(phi->id + 1) % phi->utils->nb_philo]);
			pthread_mutex_lock(&phi->utils->lock);
			printf("%ld %d has taken a right fork\n", get_time(phi->utils->start), phi->id + 1);
			printf("%ld %d is eating\n", get_time(phi->utils->start), phi->id + 1);
			// long_live = get_time(0);
			snooze(phi->utils->time_to_eat);
			pthread_mutex_unlock(&phi->utils->lock);
			pthread_mutex_unlock(&phi->utils->forks[phi->id]);
			pthread_mutex_unlock(&phi->utils->forks[(phi->id + 1) % phi->utils->nb_philo]);
			printf("%ld %d is sleeping\n", get_time(phi->utils->start), phi->id + 1);
			snooze(phi->utils->time_to_sleep);
			printf("%ld %d is thinking\n", get_time(phi->utils->start), phi->id + 1);
			// pthread_mutex_unlock(&phi->eating);
		}
		// if (phi->utils->time_to_eat > phi->utils->start)
		// 	philo_die(phi);
		// count ++;
	// }
	// else
		// printf("coucou\n");
}

void philosophers(t_philo *philo, t_utils *utils)
{
	int i;

	i = 0;
	while (i < utils->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, (void *)routine, &philo[i]);
		i += 2;
		usleep(50);
	}
	i = 1;
	while (i < utils->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, (void *)routine, &philo[i]);
		i += 2;
		usleep(50);
	}
	i = 0;
	while (i < utils->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

// int	free_all(t_philo *philo, t_utils *utils)
// {
// 	pthread_mutex_destroy();
// 	pthread_mutex_destroy();
// 	pthread_mutex_destroy();
// 	pthread_mutex_destroy();
// }

int	main(int ac, char **av)
{
	t_utils	utils;
	t_philo	*philo;

	memset(&utils, 0, sizeof(t_utils));
	if ((ac < 5 || ac > 6) || (!parse_arguments(av, &utils)))
		return (ft_error("Missing arguments || Parsing_error"));
	philo = call_philos(&utils);
	philo[0].utils->start = get_time(0);
	init_forks(&utils);
	// print_values(&utils);
	if (!(one_philo(philo, av)))
		return (0);
	philosophers(philo, &utils);
	// free_all(philo, &utils);
	return (0);
}
