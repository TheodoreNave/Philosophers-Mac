/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by tnave             #+#    #+#             */
/*   Updated: 2022/02/11 19:55:48 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_arguments(char **av, t_utils *utils)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!(give_args_values(av, i, utils)))
			return (0);
		i++;
	}
	return (1);
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
