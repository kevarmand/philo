/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_delay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:58:16 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 17:08:28 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_start(struct timeval *start, t_philo *philo)
{
	struct timeval	now;
	long			time;
	long			delay;
	
	gettimeofday(&now, NULL);
	time = get_time_diff(&now, start);
	delay = philo->data->time_to_eat / (philo->data->nb_philo - 1);
	if ((philo->data->nb_philo % 2))
	{
		time += delay * (philo->id);
		if (philo->id % 2)
			time += philo->data->time_to_eat - 200;
	}
	else if ((philo->id % 2))
		time += philo->data->time_to_eat;
	precise_sleep(&now, time);
}