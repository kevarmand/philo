/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:56:47 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/14 15:26:10 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_life(t_philo *philo);

/***
 * Attention l id du philo = data->philo_id
 * [ Ce nest pas son nom , le nom est n +1]
 */
void	philo_presentation(t_data *data)
{
	t_philo	philo;

	philo.data = data;
	pthread_mutex_lock(&data->dead);
	philo.id = data->philo_id;
	data->philo_id++;
	pthread_mutex_unlock(&data->dead);
	philo.nb_eat = 0;
	philo.left_fork = &data->fork_drawer[philo.id];
	philo.right_fork = &data->fork_drawer[(philo.id + 1) % data->nb_philo];
	philo.time_last_meat = 0;
	philo.next_action = EAT;
	
	//wait le debut de la simulation

	pthread_mutex_lock(&data->talking_stick);
	printf("philo %d is waiting\n", philo.id + 1);
	pthread_mutex_unlock(&data->talking_stick);

	wait_for_start(data);

	//distinction cas pair/impair et 
	if (philo.id % 2 == 1)
		usleep(500);
	philo_life(&philo);
}
void	annonce_action(t_philo *philo, enum e_state state)
{
	int	time;

	time = get_runtime(&philo->data->start);
	pthread_mutex_lock(&philo->data->talking_stick);
	print_msg(state, philo->id + 1, time);
	pthread_mutex_unlock(&philo->data->talking_stick);
}
int	sim_is_running(t_data *data)
{
	int	ret;

	pthread_mutex_lock(&data->dead);
	ret = data->sim_is_running;
	pthread_mutex_unlock(&data->dead);
	return (ret);
}


void	philo_life(t_philo *philo)
{
	int	time;

	while (sim_is_running(philo->data))
	{
		//if(possible) DO ACTION
	}
}
