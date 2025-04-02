/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_is_running.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:48:31 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 10:25:53 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_sim_is_running(t_sim_is_running **sim_is_running, long nb_philo)
{
	int	i;

	*sim_is_running = malloc(sizeof(t_sim_is_running) * nb_philo);
	if (!*sim_is_running)
		return (MALLOC_FAIL);
	i = 0;
	while (i < nb_philo)
	{
		(*sim_is_running)[i].state = 0;
		if (pthread_mutex_init(&(*sim_is_running)[i].mutex, NULL))
		{
			destroy_sim_is_running(*sim_is_running, i);
			*sim_is_running = NULL;
			return (MUTEX_FAIL);
		}
		i++;
	}
	return (0);
}

void destroy_sim_is_running(t_sim_is_running *sim_is_running, long nb_philo)
{
	int	i;

	if (!sim_is_running)
		return ;
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&sim_is_running[i].mutex);
		i++;
	}
	free(sim_is_running);
}
