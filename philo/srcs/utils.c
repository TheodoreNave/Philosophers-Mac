/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:14:38 by tnave             #+#    #+#             */
/*   Updated: 2022/02/10 17:12:22 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

void	*ft_calloc(int size)
{
	void	*memory;

	memory = malloc(size);
	if (!memory)
		return (NULL);
	memset(memory, 0, size);
	return (memory);
}

int	ft_strlen(char *str)
{
	int	i;

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
