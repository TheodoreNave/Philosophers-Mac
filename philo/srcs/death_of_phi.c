/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_of_phi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:31:49 by tnave             #+#    #+#             */
/*   Updated: 2022/02/15 15:42:52 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	are_they_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->utils->is_dead);
	philo->utils->dead = 1;
	pthread_mutex_unlock(&philo->utils->is_dead);
	write_thread("%ld %d %s\n", get_time(philo->utils->start), philo, DEAD);
	pthread_mutex_unlock(&philo->eating);
	return (0);
}

int	calculate_dead(t_philo *philo)
{
	if (get_time(0) - philo->life_of_phi > philo->utils->time_to_die)
	{
		are_they_dead(philo);
		return (0);
	}
	return (1);
}

void	check_dead_philo(t_philo *philo)
{
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->utils->count_protect);
		if (!philo->count)
		{
			pthread_mutex_unlock(&philo->utils->count_protect);
			return ;
		}
		pthread_mutex_unlock(&philo->utils->count_protect);
		pthread_mutex_lock(&philo->utils->is_dead);
		if (philo->utils->dead)
		{
			pthread_mutex_unlock(&philo->utils->is_dead);
			return ;
		}
		pthread_mutex_unlock(&philo->utils->is_dead);
		pthread_mutex_lock(&philo->eating);
		if (!(calculate_dead(philo)))
			return ;
		pthread_mutex_unlock(&philo->eating);
	}
	return ;
}
