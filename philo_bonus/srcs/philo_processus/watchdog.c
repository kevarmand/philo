/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:21:09 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/18 14:24:34 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief check if the philo is still alive 
 * else exit(1);
 */
void	*watchdog(void *data1)
{
	long	time_last_meal;
	t_data	*data;
	int		id;

	data = (t_data *)data1;
	id = data->philo_id;
	while (1)
	{
		sem_wait(data->sem_meal_check[id]);
		time_last_meal = data->time_last_meal;
		sem_post(data->sem_meal_check[id]);
		if (get_runtime(time_last_meal) > data->time_to_die)
		{
			print_death(data, get_runtime(data->start));
			sem_post(data->sem_death);
			ft_infinite_loop();
		}
		usleep(618);
	}
}
