/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_phi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:12:03 by tnave             #+#    #+#             */
/*   Updated: 2022/02/14 20:00:23 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	are_they_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->utils->dead = 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->utils->count_protect);
	write_thread("%ld %d %s\n", get_time(philo->utils->start), philo, DEAD);
	pthread_mutex_unlock(&philo->utils->count_protect);
	pthread_mutex_unlock(&philo->eating);
	return (0);
}

void	check_dead_philo(t_philo *philo)
{
	while (!philo->utils->dead)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->utils->count_protect);
		if (philo->count == 0)
		{
			pthread_mutex_unlock(&philo->utils->count_protect);
			return ;
		}
		pthread_mutex_unlock(&philo->utils->count_protect);
		pthread_mutex_lock(&philo->lock);
		if (philo->utils->dead)
		{
			pthread_mutex_unlock(&philo->lock);
			return ;
		}
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_lock(&philo->eating);
		if (get_time(0) - philo->life_of_phi > philo->utils->time_to_die)
			are_they_dead(philo);
		pthread_mutex_unlock(&philo->eating);
	}
	return ;
}

void	the_routine_of_philosophers(t_philo *phi)
{
	pthread_mutex_lock(&phi->utils->forks[phi->id]);
	write_thread("%ld %d %s\n", get_time(phi->utils->start), phi, TAKE_FORK);
	pthread_mutex_lock(&phi->utils->forks[(phi->id + 1)
		% phi->utils->nb_philo]);
	write_thread("%ld %d %s\n", get_time(phi->utils->start), phi, TAKE_FORK);
	pthread_mutex_lock(&phi->eating);
	phi->life_of_phi = get_time(0);
	write_thread("%ld %d %s\n", get_time(phi->utils->start), phi, EAT);
	snooze(phi->utils->time_to_eat);
	pthread_mutex_unlock(&phi->eating);
	pthread_mutex_unlock(&phi->utils->forks[phi->id]);
	pthread_mutex_unlock(&phi->utils->forks[(phi->id + 1)
		% phi->utils->nb_philo]);
	write_thread("%ld %d %s\n", get_time(phi->utils->start), phi, SLEEP);
	snooze(phi->utils->time_to_sleep);
	write_thread("%ld %d %s\n", get_time(phi->utils->start), phi, THINK);
}

void	morning_routine(t_philo *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	setup_count_and_life(phi);
	while (1)
	{
		pthread_mutex_lock(&phi->utils->count_protect);
		if (phi->utils->dead)
		{
			pthread_mutex_unlock(&phi->utils->count_protect);
			return ;
		}
		pthread_mutex_unlock(&phi->utils->count_protect);
		pthread_mutex_lock(&phi->utils->count_protect);
		if (!phi->count)
		{
			pthread_mutex_unlock(&phi->utils->count_protect);
			return ;
		}
		pthread_mutex_unlock(&phi->utils->count_protect);
		phi->count--;
		the_routine_of_philosophers(phi);
	}
	return ;
}

void	setup_count_and_life(t_philo *phi)
{
	pthread_mutex_lock(&phi->utils->count_protect);
	phi->count = phi->utils->each_philo_eat;
	pthread_mutex_unlock(&phi->utils->count_protect);
	pthread_mutex_lock(&phi->eating);
	phi->life_of_phi = get_time(0);
	pthread_mutex_unlock(&phi->eating);
}
