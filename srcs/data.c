/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:37:05 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/14 11:02:57 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_data(t_data *data)
{
	data->nb_philo = 0;
	data->philo_id = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->nb_eat = 0;
	data->sim_is_running = 1;
	data->fork_drawer = NULL;
}