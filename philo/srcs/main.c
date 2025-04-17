/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:06:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 10:58:49 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
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
