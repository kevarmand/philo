/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:09:17 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/28 14:15:39 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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