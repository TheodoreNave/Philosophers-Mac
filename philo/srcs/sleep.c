/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:28:09 by tnave             #+#    #+#             */
/*   Updated: 2022/02/14 16:28:15 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
