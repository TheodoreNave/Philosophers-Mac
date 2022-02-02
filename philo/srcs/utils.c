/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:14:38 by tnave             #+#    #+#             */
/*   Updated: 2022/02/02 12:56:20 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	snooze(time_t t)
// {
// 	time_t start;

// 	start = get_time(0);
// 	while (1)
// 	{
// 		if (get_time(0) - start >= t)
// 			break ;
// 		usleep(200);
// 	}
// }

// time_t	get_time(time_t start)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, NULL);
// 	return (time.tv_sec * 1000 + time.tv_usec / 1000);
// }

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return (1);
}

char *ft_calloc(, size_t size)
{
	t_utils *utils;

	utils = malloc(sizeof(t_utils) * utils->nb_philo);
	if (!utils)
		return (NULL);
	memset(&utils, 0, sizeof(t_utils));
	return (utils);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
