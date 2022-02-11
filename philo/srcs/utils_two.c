/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:52:14 by tnave             #+#    #+#             */
/*   Updated: 2022/02/11 16:22:22 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	one_philo(t_philo *philo, char **av)
{
	if (ft_atoi(av[1]) == 1)
	{
		printf("%ld 1 has taken a fork\n", get_time(philo->utils->start));
		printf("%d 1 has died\n", ft_atoi(av[2]));
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

void	snooze(time_t t)
{
	time_t	start;

	start = get_time(0);
	while (1)
	{
		if (get_time(0) - start >= t)
			break ;
		usleep(200);
	}
}

time_t	get_time(time_t start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - start);
}
