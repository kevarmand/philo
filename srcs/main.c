/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:06:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/01 16:47:44 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main2(t_data *data)
{
	int			err;
	pthread_t	*thread;
	pthread_t	monithread;
	
	data->start = ft_get_time() + 1000000;
	if (pthread_create(&monithread, NULL, monitoring, data))
		return (THREAD_FAIL);
	err = philosophers_arrival(data, &thread);
	if (err < 0)
	{
		free(thread);
		return (err);
	}
	else
	{
		//il em faut un signal pour tout faire bien...
	}
	philo_leave(thread, err);
	free(thread);
	pthread_join(monithread, NULL);
	return (0);
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
	if (!err)
		err = init_shared_data(&data);
	if (!err)
		err = main2(&data);
	destroy_shared_data(&data);
	printf("\n🎉  🎉  The simulation's over, time to settle the bill!  🎉  🎉\n");
	return (err);
}
