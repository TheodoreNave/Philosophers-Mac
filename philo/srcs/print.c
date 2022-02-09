#include "philosophers.h"

void print_values(t_utils *utils)
{
	printf("nb_philo = %d\n", utils->nb_philo);
	printf("time_to_die = %ld\n", utils->time_to_die);
	printf("time_to_eat = %ld\n", utils->time_to_eat);
	printf("time_to_sleep = %ld\n", utils->time_to_sleep);
	printf("each_philo_eat = %d\n", utils->each_philo_eat);
}