/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_delay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:58:16 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:26:39 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief Synchronize the start of the philosophers
 * 
 * @param start the start of the simulation
 * @param philo the philosopher structure
 */
void	wait_for_start(long start, t_philo *philo)
{
	long			now;
	long			time;
	long			delay;

	now = ft_get_time();
	time = start - now;
	delay = philo->data->time_to_eat / (philo->data->nb_philo - 1);
	if ((philo->data->nb_philo % 2))
	{
		time += delay * (philo->id);
		if (philo->id % 2)
			time += philo->data->time_to_eat - 100;
	}
	else if ((philo->id % 2))
		time += philo->data->time_to_eat;
	precise_sleep(now, time);
}
