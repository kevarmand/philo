/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:37:05 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 09:45:26 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data)
{
	data->nb_philo = 0;
	data->philo_id = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->nb_eat = 0;
	data->flag = 0;
	data->shared.lst_msg = NULL;
	data->shared.lst_last_meal = NULL;
	data->shared.tab_msg = NULL;
	data->shared.fork_drawer = NULL;
	data->shared.sim_is_running = NULL;
}

int	init_shared_data(t_data *data)
{
	int	err;

	err = 0;
	data->shared.lst_msg = malloc(sizeof(long) * data->nb_philo);
	if (!data->shared.lst_msg)
		err = MALLOC_FAIL;
	if (!err)
		data->shared.lst_last_meal = malloc(sizeof(long) * data->nb_philo);
	if (!data->shared.lst_last_meal)
		err = MALLOC_FAIL;
	if (!err)
		err = init_queue(&data->shared.tab_msg, data->nb_philo);
	if (!err)
		err = init_fork_drawer(&data->shared.fork_drawer, data->nb_philo);
	if (!err)
		err = init_sim_is_running(&data->shared.sim_is_running, data->nb_philo);
	return (err);
}

void	destroy_shared_data(t_data *data)
{
	destroy_queue(data->shared.tab_msg, data->nb_philo);
	data->shared.tab_msg = NULL;
	destroy_fork_drawer(data->shared.fork_drawer, data->nb_philo);
	data->shared.fork_drawer = NULL;
	destroy_sim_is_running(data->shared.sim_is_running, data->nb_philo);
	data->shared.sim_is_running = NULL;
	free(data->shared.lst_msg);
	data->shared.lst_msg = NULL;
	free(data->shared.lst_last_meal);
	data->shared.lst_last_meal = NULL;
}
