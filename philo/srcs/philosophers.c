/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:04:57 by tnave             #+#    #+#             */
/*   Updated: 2022/02/15 15:42:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	one_philo(t_philo *philo, char **av)
{
	if (ft_atoi(av[1]) == 1)
	{
		philo[0].utils->start = get_time(0);
		printf("%ld 1 has taken a fork\n", get_time(philo->utils->start));
		printf("%d 1 died\n", ft_atoi(av[2]));
		return (0);
	}
	return (1);
}

int	init_forks(t_utils *utils)
{
	int	i;

	i = 0;
	utils->forks = ft_calloc(sizeof(pthread_mutex_t) * utils->nb_philo);
	if (!utils->forks)
		return (0);
	while (i < utils->nb_philo)
	{
		pthread_mutex_init(&utils->forks[i], NULL);
		i++;
	}
	return (1);
}

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
	pthread_mutex_init(&philo->utils->lock, NULL);
	pthread_mutex_init(&philo->utils->count_protect, NULL);
	pthread_mutex_init(&philo->utils->is_dead, NULL);
	return (philo);
}

int	main(int ac, char **av)
{
	t_utils	utils;
	t_philo	*philo;

	memset(&utils, 0, sizeof(t_utils));
	if ((ac < 5 || ac > 6) || (!parse_arguments(av, &utils)))
		return (ft_error("Missing arguments || Parsing Error\n"));
	philo = call_philos(&utils);
	if (!philo)
		return (free_all(philo, &utils) && ft_error("Calloc error\n"));
	if (!(init_forks(&utils)))
		return (free_all(philo, &utils) && ft_error("Calloc Error\n"));
	if (!(one_philo(philo, av)))
		return (free_all(philo, &utils));
	if (!(philosophers(philo, &utils)))
		return (free_all(philo, &utils) && (1));
	free_all(philo, &utils);
	return (0);
}
