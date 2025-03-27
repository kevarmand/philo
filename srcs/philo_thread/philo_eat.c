/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:21 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 14:55:01 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo, struct timeval *now)
{
	pthread_mutex_lock(philo->left_fork);
	gettimeofday(now, NULL);
	if (!is_sim_running(philo->data, philo->id))
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	annonce_action(philo, FORK, now);
	pthread_mutex_lock(philo->right_fork);
	gettimeofday(now, NULL);
	if (!is_sim_running(philo->data, philo->id))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	annonce_action(philo, FORK, now);
	annonce_action(philo, EATING, now);
	time_copy(&philo->time_last_meat, now);
	precise_sleep(now, (long)philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->nb_eat++;
}
