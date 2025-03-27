/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:09:17 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 16:53:56 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	check_starvation(t_philo *philo)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, NULL);
// 	if (get_time_diff(&philo->time_last_meat, &time) > philo->data->time_to_die)
// 	{
// 		philo_die(philo, &time);
// 		return (1);
// 	}
// 	return (0);
// }


int	is_sim_running(t_data *data, int id)
{
	int	ret;

	pthread_mutex_lock(&data->tab_queue[id].mutex);
	ret = data->tab_queue[id].sim_is_running;
	pthread_mutex_unlock(&data->tab_queue[id].mutex);
	if (ret == 1)
		return (1);
	return (0);
}