/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:42:35 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/01 16:38:02 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_update(long *lst_instr, t_data *data)
{
	int		i;
	int		nb_philo;

	nb_philo = data->nb_philo;
	i = 0;
	while (i < nb_philo)
	{
		if (lst_instr[i] == -1)
			lst_instr[i] = print_get(&data->shared.tab_msg[i]);
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
			if (min == -1 || (M_TIME & (lst_instr[i])) < (M_TIME & min))
				min = lst_instr[i];
		}
		i++;
	}
	return (min);
}