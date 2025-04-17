/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:56:47 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:20:35 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_life(t_philo *philo);

/***
 * @brief initialize the philosopher (data/wait for start)
 * 
 * * @param *data the data structure (void *)
 */
void	*philo_presentation(void *data1)
{
	t_philo	philo;
	t_data	*data;

	data = (t_data *)data1;
	philo.data = data;
	pthread_mutex_lock(&data->shared.sim_is_running[0].mutex);
	philo.id = data->philo_id;
	data->philo_id++;
	pthread_mutex_unlock(&data->shared.sim_is_running[0].mutex);
	philo.nb_eat = 0;
	philo.left_fork = &data->shared.fork_drawer[philo.id];
	philo.right_fork = &data->shared.fork_drawer[(philo.id + 1)
		% data->nb_philo];
	philo.time_last_meat = data->start;
	philo.next_action = EAT;
	wait_for_start(data->start, &philo);
	philo_life(&philo);
	return (NULL);
}
