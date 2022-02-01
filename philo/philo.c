/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:14:49 by tnave             #+#    #+#             */
/*   Updated: 2022/02/01 13:15:26 by tnave            ###   ########.fr       */
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

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t t1;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);						// Finir l'execution normalement / Terminer le processs / NULL car nous ne retournons rien
	return (0);
}