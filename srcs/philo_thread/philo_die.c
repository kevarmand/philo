/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:09:17 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/20 10:55:06 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starvation(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (get_time_diff(&philo->time_last_meat, &time) > philo->data->time_to_die)
	{
		philo_die(philo, &time);
		return (1);
	}
	return (0);
}

int	sim_is_running(t_data *data)
{
	int	ret;

	pthread_mutex_lock(&data->dead);
	ret = data->sim_is_running;
	pthread_mutex_unlock(&data->dead);
	if (ret == -1)
		return (1);
	return (0);
}

void	philo_die(t_philo *philo, struct timeval *now)
{
	annonce_action(philo, DIED, now);
	pthread_mutex_lock(&philo->data->dead);
	philo->data->sim_is_running = philo->id;
	pthread_mutex_unlock(&philo->data->dead);
}