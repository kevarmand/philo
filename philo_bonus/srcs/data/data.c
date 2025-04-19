/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:37:05 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/19 10:10:51 by kearmand         ###   ########.fr       */
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
	data->start = 0;
	data->sem_forks_count = NULL;
	data->sem_forks_access = NULL;
	data->sem_main = NULL;
	data->sem_death = NULL;
	data->sem_full = NULL;
	data->sem_print = NULL;
	data->sem_meal_check = NULL;
	data->nb_eat_done = 0;
	data->time_last_meal = 0;
	data->next_action = EAT;
	data->simulation = 0;
	data->pid = NULL;
}
