/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:06:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 12:52:05 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	int			err;
	t_data		data;
	pthread_t	*thread;
	pthread_t	printer_thread;

	init_data(&data);

	//parsing des arguments
	err = parsing(&data, ac, av);
	if (err)
		return (err);
	//convertir les ms en us
	data.time_to_die *= 1000;
	data.time_to_eat *= 1000;
	data.time_to_sleep *= 1000;
	//appel de la fonction pour creer les fourchette
	if (!err)
		err = create_fork(&data);
	if (err)
		return (err);
	//lock the talking stick for the start
	pthread_mutex_lock(&data.talking_stick);
	//Initialisiation du temps
	gettimeofday(&data.start, NULL);
	data.start.tv_sec += 1;

	//Creation du queue de message
	err = print_init(&data.tab_queue, data.nb_philo);
	if (err)
		return (err);
	//lancement de la fonction printer
	pthread_create(&printer_thread, NULL, &printer, &data);//pas de protection parce que YOLO
	printf("start\n");
	
	//creation des philo
	if (!err)
		err = philosophers_arrival(&data, &thread);
	if (err)
		return (err);


	
	
	//unlock the talking stick for the start TOP DEPART
	pthread_mutex_unlock(&data.talking_stick);


	
	//wait le retour des philo
	philo_leave(&data, thread, data.nb_philo);
	printf("end_main\n");
	pthread_join(printer_thread, NULL);
	//destroy les fourchette
	destroy_fork_drawer(&data, data.nb_philo);
	//destroy les mutex
	pthread_mutex_destroy(&data.talking_stick);
	pthread_mutex_destroy(&data.dead);
	//free les thread
	free(thread);
	//return the error
	return (err);
}
