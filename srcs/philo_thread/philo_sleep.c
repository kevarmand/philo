/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:08:38 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/28 16:19:48 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo, struct timeval *now)
{
	long	real_time_to_sleep;
	long	diff;

	annonce_action(philo, SLEEPING, now);
	diff = get_time_diff(&philo->time_last_meat, now);
	if (diff + philo->data->time_to_sleep > philo->data->time_to_die)
	{
		real_time_to_sleep = philo->data->time_to_die - diff;
		precise_sleep(now, real_time_to_sleep);
		gettimeofday(now, NULL);
	}
	else
	{
		real_time_to_sleep = philo->data->time_to_sleep;
		precise_sleep(now, real_time_to_sleep);
		gettimeofday(now, NULL);
	}
}