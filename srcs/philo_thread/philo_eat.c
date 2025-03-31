/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:21 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/31 13:16:08 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	free_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->state = philo->id;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->state = philo->id;
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

int	try_take_fork(t_philo *philo, t_fork *fork, struct timeval *time)
{
	int	ret;
	
	ret = 0;
	pthread_mutex_lock(&fork->mutex);
	if (fork->state != -1 && fork->state != philo->id)
	{
		fork->state = -1;
		ret = 1;
	}
	pthread_mutex_unlock(&fork->mutex);
	if (ret == 1)
		annonce_action(philo, FORK, time);
	return (ret);
}

void	take_forks(t_philo *philo, struct timeval *time)
{
	int				fork_left;
	int				fork_right;

	fork_left = 0;
	fork_right = 0;
	while (fork_left == 0 && fork_right == 0)
	{
		fork_left = try_take_fork(philo, philo->left_fork, time);
		fork_right = try_take_fork(philo, philo->right_fork, time);
		if (fork_left == 1 || fork_right == 1)
			break ;	
		usleep(10);
		gettimeofday(time, NULL);
	}
	while (fork_left == 0)
	{
		fork_left = try_take_fork(philo, philo->left_fork, time);
		usleep(10);
		gettimeofday(time, NULL);
	}
	while (fork_right == 0)
	{
		fork_right = try_take_fork(philo, philo->right_fork, time);
		usleep(10);
		gettimeofday(time, NULL);
	}
}

void	philo_eat(t_philo *philo, struct timeval *now)
{
	take_forks(philo, now);
	gettimeofday(now, NULL);
	annonce_action(philo, EATING, now);
	philo->time_last_meat = *now;
	precise_sleep(now, (long)philo->data->time_to_eat);
	free_forks(philo);
	philo->nb_eat++;
}
