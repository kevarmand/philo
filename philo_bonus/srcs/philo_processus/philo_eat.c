/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:21 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/19 16:35:29 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_forks(t_data *data);
static void	take_forks(t_data *data, long *time);

/***
 * @brief try to take the forks and eat
 * 
 * @param *philo the philosopher structure
 * @param *now the time
 */
void	philo_eat(t_data *data, long *now)
{
	take_forks(data, now);
	sem_wait(data->sem_meal_check[data->philo_id]);
	data->time_last_meal = *now;
	sem_post(data->sem_meal_check[data->philo_id]);
	annonce_action(data, EATING, *now);
	precise_sleep(*now, data->time_to_eat);
	free_forks(data);
	data->nb_eat_done++;
}

static void	free_forks(t_data *data)
{
	sem_post(data->sem_forks_count);
	sem_post(data->sem_forks_count);
}

static void	take_forks(t_data *data, long *time)
{
	sem_wait(data->sem_forks_access);
	sem_wait(data->sem_forks_count);
	annonce_action(data, FORK, *time);
	sem_wait(data->sem_forks_count);
	*time = ft_get_time();
	annonce_action(data, FORK, *time);
	sem_post(data->sem_forks_access);
}
