/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:14:49 by tnave             #+#    #+#             */
/*   Updated: 2022/02/02 11:20:02 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void *routine()
// {
// 	printf("Coucou from thread\n");
// }


// printf("time philo_1 has taken a fork\n");
// printf("time philo_1 is eating\n");
// printf("time philo_1 is sleeping\n");
// printf("time philo_1 is thinking\n");
// printf("time philo_1 died\n");

void print_values(t_utils *utils)
{
	printf("nb_philo = %d\n", utils->nb_philo);
	printf("time_to_die = %d\n", utils->time_to_die);
	printf("time_to_eat = %d\n", utils->time_to_eat);
	printf("time_to_sleep = %d\n", utils->time_to_sleep);
	printf("each_philo_eat = %d\n", utils->each_philo_eat);
}

int	give_values_args(char **av, int i, t_utils *utils)
{
	if (ft_atoi(av[i]) > 0)
	{
		utils->nb_philo = ft_atoi(av[1]);
		utils->time_to_die = ft_atoi(av[2]);
		utils->time_to_eat = ft_atoi(av[3]);
		utils->time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			utils->each_philo_eat = ft_atoi(av[5]);
		return (1);
	}
	else
		return (0);
}


int	parse_arguments(char **av, t_utils *utils)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!(give_values_args(av, i, utils)))
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_utils utils;

	memset(&utils, 0, sizeof(t_utils));
	if (ac < 5 || ac > 6)
		return (0);
	if (!(parse_arguments(av, &utils)))
		return (1);
	print_values(&utils);
	// pthread_create(&t1, NULL, &routine, NULL);
	// pthread_join(t1, NULL);						// Finir l'execution normalement / Terminer le processs / NULL car nous ne retournons rien
	return (0);
}

