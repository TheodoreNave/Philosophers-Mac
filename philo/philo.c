/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:14:49 by tnave             #+#    #+#             */
/*   Updated: 2022/02/01 14:53:16 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine()
{
	printf("Coucou from thread\n");
}



// printf("time philo_1 has taken a fork\n");
// printf("time philo_1 is eating\n");
// printf("time philo_1 is sleeping\n");
// printf("time philo_1 is thinking\n");
// printf("time philo_1 died\n");



// need to atoi the number in av[1] to pass into array of pthread_t ?
// av[1] numbers of philosophers
// av[2] time_to_die
// av[3] time_to_eat
// av[4] time_to_sleep

void print_values(t_utils *utils)
{
	printf("nb_philo = %d\n", utils->nb_philo);
	printf("time_to_die = %d\n", utils->time_to_die);
	printf("time_to_eat = %d\n", utils->time_to_eat);
	printf("time_to_sleep = %d\n", utils->time_to_sleep);
	printf("each_philo_eat = %d\n", utils->each_philo_eat);
}

int	give_values_args(char *av, t_utils *utils)
{
	utils->nb_philo = atoi(av[1]);
	utils->time_to_die = atoi(av[2]);
	utils->time_to_eat = atoi(av[3]);
	utils->time_to_sleep = atoi(av[4]);
	utils->each_philo_eat = atoi(av[5]);
}


int	parse_arguments(char **av, t_utils *utils)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	give_values_args(av, utils);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t t1;
	t_utils utils;

	if (ac != 6)
		return (0);
	memset(&utils, 0, sizeof(t_utils));
	parse_arguments(av, &utils);
	print_values(&utils);
	// pthread_create(&t1, NULL, &routine, NULL);
	// pthread_join(t1, NULL);						// Finir l'execution normalement / Terminer le processs / NULL car nous ne retournons rien
	return (0);
}