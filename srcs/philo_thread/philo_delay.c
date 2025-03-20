/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_delay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:58:16 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/20 09:02:57 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"




/****
 * void    ft_delay(t_philo *philo)
{
    if (philo->nb_philos % 2)
    {
        if (philo->id % 2 && philo->id != 1)
            ft_usleep(philo->time_to_eat / 2);
        if (!(philo->id % 2))
            ft_usleep(philo->time_to_eat / 2 + 1);
    }
    else if (!(philo->id % 2))
        ft_usleep(1);
}
 */

void	wait_for_start(struct timeval *start, t_philo *philo)
{
	struct timeval	now;
	long			time;
	long			delay;
	
	gettimeofday(&now, NULL);
	time = get_time_diff(&now, start);
	delay = philo->data->time_to_eat / (philo->data->nb_philo - 1);
	if ((philo->data->nb_philo % 2))
	{
		time += delay * (philo->id);
		if (philo->id % 2)
			time += philo->data->time_to_eat;
	}
	else if ((philo->id % 2))
		time += philo->data->time_to_eat;
	precise_sleep(&now, time);
	//gettimeofday(&now, NULL);
	//annonce_action(philo, TEST, &now);
}