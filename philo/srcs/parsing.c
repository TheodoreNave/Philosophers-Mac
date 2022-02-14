/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:04:34 by tnave             #+#    #+#             */
/*   Updated: 2022/02/14 15:34:08 by tnave            ###   ########.fr       */
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

int	check_sign(const char *str, long int *i, int sign)
{
	if (str[*i] == '-')
		return (1);
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

int	ft_atoi(char *str)
{
	long int	i;
	long int	res;
	long int	sign;

	i = 0;
	sign = 1;
	res = 0;
	sign = check_sign(str, &i, sign);
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	if (sign * res > 2147483647 || sign * res < -2147483648)
		return (0);
	return (sign * res);
}
