/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:42:35 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 13:00:14 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_update(long *lst_instr, t_data *data)
{
	int		i;
	long	min;
	int		nb_philo;

	nb_philo = data->nb_philo;
	i = 0;
	while (i < nb_philo)
	{
		if (lst_instr[i] == -1)
			lst_instr[i] = print_get(&data->tab_queue[i]);
		i++;
	}
}

long	check_min(long *lst_instr, t_data *data)
{
	long	min;
	int		i;
	int		nb_philo;
	

	nb_philo = data->nb_philo;
	i = 0;
	min = -1;
	while (i < nb_philo)
	{
		if (lst_instr[i] != -1)
		{
			if (min == -1 || (M_INST & (lst_instr[i])) < (M_INST & min))
				min = lst_instr[i];
		}
		i++;
	}
	return (min);
}