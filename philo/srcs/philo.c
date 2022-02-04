/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:14:49 by tnave             #+#    #+#             */
/*   Updated: 2022/02/04 16:31:02 by tnave            ###   ########.fr       */
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

// void protect(t_utils *utils)
// {
	// mutex
// }


void print_values(t_utils *utils)
{
	printf("nb_philo = %d\n", utils->nb_philo);
	printf("time_to_die = %ld\n", utils->time_to_die);
	printf("time_to_eat = %ld\n", utils->time_to_eat);
	printf("time_to_sleep = %ld\n", utils->time_to_sleep);
	printf("each_philo_eat = %d\n", utils->each_philo_eat);
}

int	give_args_values(char **av, int i, t_utils *utils)
{
	if (ft_atoi(av[i]) > 0)
	{
		utils->nb_philo = ft_atoi(av[1]);
		utils->time_to_die = ft_atoi(av[2]);
		utils->time_to_eat = ft_atoi(av[3]);
		utils->time_to_sleep = ft_atoi(av[4]);
		utils->each_philo_eat = -1;
		if (av[5])
			utils->each_philo_eat = ft_atoi(av[5]);
		return (1);
	}
	else
		return (0);
}

void init_philos(t_utils *utils)
{
	int i;

	i = 1;
	utils->forks = ft_calloc(sizeof(utils->forks) * utils->nb_philo);
	while (i <= utils->nb_philo)
	{
		pthread_mutex_init(&utils->forks[i], NULL);
		i++;
	}
}

// void philosophers();

int	parse_arguments(char **av, t_utils *utils)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!(give_args_values(av, i, utils)))
			return (0);
		i++;
	}
	return (1);
}

t_philo *call_philos(t_utils *utils)
{
	int 		nb_philo;
	t_philo 	*philo;
	int	 		i;

	nb_philo = utils->nb_philo;
	i = 1;
	philo = ft_calloc(sizeof(t_philo) * nb_philo);
	while (i <= nb_philo)
	{
		philo[i].id = i;
		philo[i].utils = utils;
		pthread_mutex_init(&philo[i].eating, NULL);
		i++;
	}
	return (philo);
}

int main(int ac, char **av)
{
	t_utils utils;
	t_philo *philo;

	memset(&utils, 0, sizeof(t_utils));
	if ((ac < 5 || ac > 6) || (!parse_arguments(av, &utils)))
		return (ft_error("Missing arguments || Parsing_error"));
	// if only one philo fonctions
	init_philos(&utils);
	print_values(&utils);
	philo = call_philos(&utils);
	printf("philo->utils->time to die = %ld\n", philo->utils->time_to_die);
	// pthread_create(&t1, NULL, &routine, NULL);
	// pthread_join(t1, NULL);						// Finir l'execution normalement / Terminer le processs / NULL car nous ne retournons rien
	// free_all();
	// philosophers(&utils);
	return (0);
}

