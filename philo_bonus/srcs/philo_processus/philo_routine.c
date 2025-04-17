/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:22:03 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/17 10:59:59 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	next_action(t_data *data);

/***
 * @brief philosopher routine
 * 
 * @param *philo the philosopher structure
 */
void	philo_life(t_data *data)
{
	long		time;
	static void	(*action[3])(t_data *data, long *now) = {
		philo_eat,
		philo_sleep,
		philo_think
	};

	while (1)
	{
		time = ft_get_time();
		if (data->nb_eat != -1 && data->nb_eat_done >= data->nb_eat)
			break ;
		action[data->next_action](data, &time);
		next_action(data);
	}
	annonce_action(data, END, time);
	exit(0);
}

static void	next_action(t_data *data)
{
	if (data->next_action == EAT)
		data->next_action = SLEEP;
	else if (data->next_action == SLEEP)
		data->next_action = THINK;
	else if (data->next_action == THINK)
		data->next_action = EAT;
}
