/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:14:49 by tnave             #+#    #+#             */
/*   Updated: 2022/02/11 20:13:12 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*call_philos(t_utils *utils)
{
	int			i;
	int			nb_philo;
	t_philo		*philo;

	i = 0;
	nb_philo = utils->nb_philo;
	philo = ft_calloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		return (NULL);
	while (i < nb_philo)
	{
		philo[i].id = i;
		philo[i].utils = utils;
		pthread_mutex_init(&philo[i].eating, NULL);
		i++;
	}
	return (philo);
}

// int print_action_philos(t_philo *philo)
// {



// }


void 	check_dead_philo(t_philo *philo)
{
	while (!philo->utils->dead)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->eating);
		if (get_time(0) - philo->utils->life_of_phi >= philo->utils->time_to_die)
		{
			printf("%ld %d %s\n", get_time(philo->utils->start), philo->id + 1, DEAD);
			philo->utils->dead = 1;
			pthread_mutex_unlock(&philo->eating);
			return ;
		}
		pthread_mutex_unlock(&philo->eating);
	}
	return ;
}

void	routine(t_philo *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	philo->utils->life_of_phi = get_time(0);
	phi->count = phi->utils->each_philo_eat;
	while (1)
	{
		if (philo->utils->dead == 1 || phi->count == 0)
			break ;
		phi->count--;
		pthread_mutex_lock(&phi->utils->forks[phi->id]);
		printf("%ld %d %s\n", get_time(phi->utils->start), phi->id + 1, TAKE_LEFT_FORK);
		pthread_mutex_lock(&phi->utils->forks[(phi->id + 1) % phi->utils->nb_philo]);
		printf("%ld %d %s\n", get_time(phi->utils->start), phi->id + 1, TAKE_RIGHT_FORK);
		pthread_mutex_lock(&phi->eating);
		phi->utils->life_of_phi = get_time(0);
		printf("%ld %d %s\n", get_time(phi->utils->start), phi->id + 1, EAT);
		snooze(phi->utils->time_to_eat);
		pthread_mutex_unlock(&phi->eating);
		pthread_mutex_unlock(&phi->utils->forks[phi->id]);
		pthread_mutex_unlock(&phi->utils->forks[(phi->id + 1) % phi->utils->nb_philo]);
		printf("%ld %d %s\n", get_time(phi->utils->start), phi->id + 1, SLEEP);
		snooze(phi->utils->time_to_sleep);
		printf("%ld %d %s\n", get_time(phi->utils->start), phi->id + 1, THINK);
	}
	return ;
}

void	philosophers(t_philo *philo, t_utils *utils)	// Change value of return
{
	int	i;

	i = 0;
	philo[0].utils->start = get_time(0);
	philo->utils->life_of_phi = get_time(0);
	while (i < utils->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)routine, &philo[i]) != 0)
			return ;
		if (pthread_create(&philo[i].control, NULL, (void *)check_dead_philo, &philo[i]) != 0)
			return ;
		i += 2;
		usleep(50);
	}
	i = 1;
	while (i < utils->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)routine, &philo[i]) != 0)
			return ;
		if (pthread_create(&philo[i].control, NULL, (void *)check_dead_philo, &philo[i]) != 0)
			return ;
		i += 2;
		usleep(50);
	}
	i = 0;
	while (i < utils->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return ;
		if (pthread_join(philo[i].control, NULL) != 0)
		usleep(50);
		i++;
	}
	return ;
}

int	free_all(t_philo *philo, t_utils *utils)
{
	int i = 0;
	while (i < utils->nb_philo)
	{
		pthread_mutex_destroy(&philo[i].eating);
		pthread_mutex_destroy(&utils->forks[i]);
		i++;
	}
	if (philo)
		free(philo);
	if (utils->forks)
		free(utils->forks);
	return (1);
}

int	main(int ac, char **av)
{
	t_utils	utils;
	t_philo	*philo;

	memset(&utils, 0, sizeof(t_utils));
	if ((ac < 5 || ac > 6) || (!parse_arguments(av, &utils)))
		return (ft_error("Missing arguments || Parsing_error\n"));
	philo = call_philos(&utils);
	if (!philo)
		return (ft_error("Calloc error\n"));
	philo[0].utils->start = get_time(0);
	if (!(init_forks(&utils)))
		return (ft_error("Callocqq error\n"));
	print_values(&utils);
	if (!(one_philo(philo, av)))
		return (1);
	philosophers(philo, &utils);	// to_protect
	free_all(philo, &utils);
	return (0);
}
