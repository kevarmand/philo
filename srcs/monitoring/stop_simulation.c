/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:43:36 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:44:41 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief stop the simulation
 * 
 * @param *data the data structure
 */
void	end_simulation(t_data *data, int status)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->shared.sim_is_running[i].mutex);
		data->shared.sim_is_running[i].state = 0;
		pthread_mutex_unlock(&data->shared.sim_is_running[i].mutex);
		i++;
	}
	printf("\n");
	if (status == 1)
		printf("🚑  🚑  A philosopher died, the simulation is over  🚑  🚑\n");
	else if (status == 2)
	{
		printf("🎉  🎉  Everyone has finished eating, the simulation is over");
		printf("  🎉  🎉\n");
	}
	printf("\n");
}
