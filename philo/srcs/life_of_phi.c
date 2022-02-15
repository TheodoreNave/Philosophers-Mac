/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_phi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:12:03 by tnave             #+#    #+#             */
/*   Updated: 2022/02/15 15:32:36 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	setup_count_and_life(t_philo *phi)
{
	pthread_mutex_lock(&phi->utils->count_protect);
	phi->count = phi->utils->each_philo_eat;
	pthread_mutex_unlock(&phi->utils->count_protect);
	pthread_mutex_lock(&phi->eating);
	phi->life_of_phi = get_time(0);
	pthread_mutex_unlock(&phi->eating);
	return (0);
}

void	the_routine_of_philosophers(t_philo *phi)
{
	pthread_mutex_lock(&phi->utils->count_protect);
	phi->count--;
	pthread_mutex_unlock(&phi->utils->count_protect);
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
		pthread_mutex_lock(&phi->utils->is_dead);
		if (phi->utils->dead)
		{
			pthread_mutex_unlock(&phi->utils->is_dead);
			return ;
		}
		pthread_mutex_unlock(&phi->utils->is_dead);
		pthread_mutex_lock(&phi->utils->count_protect);
		if (!phi->count)
		{
			pthread_mutex_unlock(&phi->utils->count_protect);
			return ;
		}
		pthread_mutex_unlock(&phi->utils->count_protect);
		the_routine_of_philosophers(phi);
	}
	return ;
}
