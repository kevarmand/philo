/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:06:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 15:20:32 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int start_simulation(t_data *data)
{
	int			err;
	pthread_t	*thread;
	pthread_t	monithread;
	
	data->start = ft_get_time() + 1000000;
	err = philosophers_arrival(data, &thread);
	if (err  == data->nb_philo)
	{
		if (!pthread_create(&monithread, NULL, watchdog, data))
			pthread_join(monithread, NULL);
	}	
	philo_leave(thread, err);
	free (thread);
	return (err);
}

int main(int ac, char **av)
{
	int			err;
	t_data		data;

	init_data(&data);
	err = parsing(&data, ac, av);
	data.time_to_die *= 1000;
	data.time_to_eat *= 1000;
	data.time_to_sleep *= 1000;
	if (!err && data.nb_philo == 1)
		return (alone_launch(&data));
	if (!err)
		err = init_shared_data(&data);
	if (!err)
		err = start_simulation(&data);
	destroy_shared_data(&data);
	return (err);
}
