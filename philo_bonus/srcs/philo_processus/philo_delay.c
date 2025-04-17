/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_delay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:58:16 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/17 11:50:42 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief Synchronize the start of the philosophers
 * 
 * @param start the start of the simulation
 * @param philo the philosopher structure
 */
void	wait_for_start(long start, t_data *data)
{
	long			now;
	long			time;
	long			delay;

	now = ft_get_time();
	time = start - now;
	delay = data->time_to_eat / (data->nb_philo - 1);
	if ((data->nb_philo % 2))
	{
		time += delay * (data->philo_id);
		if (data->philo_id % 2)
			time += data->time_to_eat - 100;
	}
	else if ((data->philo_id % 2))
		time += data->time_to_eat;
	precise_sleep(now, time);
}
