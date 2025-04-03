/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:47:13 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 10:13:50 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo, long *now)
{
	annonce_action(philo, THINKING, *now);
}

int	is_sim_running(t_data *data, int id)
{
	int	ret;

	pthread_mutex_lock(&data->shared.sim_is_running[id].mutex);
	ret = data->shared.sim_is_running[id].state;
	pthread_mutex_unlock(&data->shared.sim_is_running[id].mutex);
	return (ret);
}
