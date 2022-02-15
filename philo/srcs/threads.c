/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:13:18 by tnave             #+#    #+#             */
/*   Updated: 2022/02/15 14:10:00 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_thread(char *str, time_t time, t_philo *philo, char *define)
{
	pthread_mutex_lock(&philo->utils->is_dead);
	if (!philo->utils->dead)
	{
		printf(str, time, philo->id + 1, define);
		pthread_mutex_unlock(&philo->utils->is_dead);
		return ;
	}
	pthread_mutex_unlock(&philo->utils->is_dead);
	pthread_mutex_lock(&philo->utils->lock);
	if (!philo->utils->write_dead)
	{
		philo->utils->write_dead = 1;
		printf(str, time, philo->id + 1, define);
		pthread_mutex_unlock(&philo->utils->lock);
		return ;
	}
	pthread_mutex_unlock(&philo->utils->lock);
	return ;
}

int	join_thread(t_philo *philo, t_utils *utils)
{
	int	i;

	i = 0;
	while (i < utils->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (0);
		if (pthread_join(philo[i].control, NULL) != 0)
			return (0);
		usleep(50);
		i++;
	}
	return (1);
}

int	philosophers(t_philo *philo, t_utils *utils)
{
	philo[0].utils->start = get_time(0);
	philo_pair(philo, utils);
	philo_impair(philo, utils);
	if (!(join_thread(philo, utils)))
		return (0);
	return (1);
}

int	philo_impair(t_philo *philo, t_utils *utils)
{
	int	i;

	i = 1;
	while (i < utils->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL,
				(void *)morning_routine, &philo[i]) != 0)
			return (0);
		if (pthread_create(&philo[i].control, NULL,
				(void *)check_dead_philo, &philo[i]) != 0)
			return (0);
		i += 2;
		usleep(50);
	}
	return (1);
}

int	philo_pair(t_philo *philo, t_utils *utils)
{
	int	i;

	i = 0;
	while (i < utils->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL,
				(void *)morning_routine, &philo[i]) != 0)
			return (0);
		if (pthread_create(&philo[i].control, NULL,
				(void *)check_dead_philo, &philo[i]) != 0)
			return (0);
		i += 2;
		usleep(50);
	}
	return (1);
}
