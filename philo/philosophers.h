/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:15:14 by tnave             #+#    #+#             */
/*   Updated: 2022/02/01 14:44:20 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

// typedef struct 	s_list_utils
// {
// 	struct s_list_utils 	*next;
// 	i;

// }				t_list_utils;

typedef struct 					s_utils
{
	// t_list_utils 		list;
	int							nb_philo;
	__useconds_t				time_to_die;
	__useconds_t				time_to_eat;
	__useconds_t				time_to_sleep;
	int							each_philo_eat;

}								t_utils;

int	ft_atoi(const char *str);

#endif