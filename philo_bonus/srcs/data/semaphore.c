/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:34:44 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/17 15:56:24 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		create_semaphore(const char *name, int value, sem_t **sem);
static void		destroy_semaphore(sem_t **sem, const char *name);

void	destroy_semaphores(t_data *data)
{
	int	i;
	static char sem_array[30] = "/sem_meal_check_XX";
	
	destroy_semaphore(&data->sem_forks_count, "/sem_forks_count");
	destroy_semaphore(&data->sem_forks_access, "/sem_forks_access");
	destroy_semaphore(&data->sem_print, "/sem_print");
	i = 0;
	while (i < data->nb_philo)
	{
		sem_array[17] = (i / 16) + 'A';
		sem_array[18] = (i % 16) + 'A';
		destroy_semaphore(&data->sem_meal_check[i], sem_array);
		i++;
	}
	free(data->sem_meal_check);
	data->sem_meal_check = NULL;
}

int	init_semaphores(t_data *data)
{
	int	err;
	int	i;
	static char sem_array[30] = "/sem_meal_check_XX";

	err = 0;
	err += create_semaphore("/sem_forks_count", data->nb_philo, &data->sem_forks_count);
	err += create_semaphore("/sem_forks_access", 1, &data->sem_forks_access);
	err += create_semaphore("/sem_print", 1, &data->sem_print);
	i = 0;
	data->sem_meal_check = malloc(sizeof(sem_t *) * data->nb_philo);
	if (!data->sem_meal_check)
		return (error_msg(MALLOC_FAIL));
	while (i < data->nb_philo)
	{
		sem_array[17] = (i / 16) + 'A';
		sem_array[18] = (i % 16) + 'A';
		err += create_semaphore(sem_array, 1, &data->sem_meal_check[i]);
		i++;
	}
	return (err);
}

static int	create_semaphore(const char *name, int value, sem_t **sem)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (*sem == SEM_FAILED)
	{
		error_msg(SEM_FAIL);
		*sem = NULL;
		return (-1);
	}
	return (0);
}

static void	destroy_semaphore(sem_t **sem, const char *name)
{
	if (*sem)
	{
		sem_close(*sem);
		sem_unlink(name);
		*sem = NULL;
	}
}