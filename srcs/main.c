/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:06:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/14 11:42:41 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	int			err;
	t_data		data;
	pthread_t	*thread;

	init_data(&data);

	//parsing des arguments
	err = parsing(&data, ac, av);
	if (err)
		return (err);

	//appel de la fonction pour creer les fourchette
	if (!err)
		err = create_fork(&data);
	if (err)
		return (err);
	//lock the talking stick for the start
	pthread_mutex_lock(&data.talking_stick);

	//creation des philo
	if (!err)
		err = philosophers_arrival(&data, &thread);
	if (err)
		return (err);

	//Initialisiation du temps
	gettimeofday(&data.start, NULL);
	data.start.tv_sec += 1;
	
	//unlock the talking stick for the start
	pthread_mutex_unlock(&data.talking_stick);
	
	//wait le retour des philo
	philo_leave(&data, thread, data.nb_philo);
	
	//destroy les fourchette
	//destroy_fork_drawer(&data, data.nb_philo);
	return (err);
}
