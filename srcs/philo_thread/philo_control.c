/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:21:09 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:25:59 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief check if the simulation is still running
 */
int	is_sim_running(t_data *data, int id)
{
	int	ret;

	pthread_mutex_lock(&data->shared.sim_is_running[id].mutex);
	ret = data->shared.sim_is_running[id].state;
	pthread_mutex_unlock(&data->shared.sim_is_running[id].mutex);
	return (ret);
}
