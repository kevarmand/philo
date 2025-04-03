/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:42:35 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:48:25 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief update the message list
 * 
 * @param *data the data structure
 */
void	update_msg(t_data *data)
{
	int		i;
	int		nb_philo;
	long	*lst_instr;

	lst_instr = data->shared.lst_msg;
	nb_philo = data->nb_philo;
	i = 0;
	while (i < nb_philo)
	{
		if (lst_instr[i] == -1)
			lst_instr[i] = get_msg(&data->shared.tab_msg[i]);
		i++;
	}
}

/***
 * @brief get the latest message
 * 
 * @param *data the data structure
 * @return the latest message
 */
long	get_latest(t_data *data)
{
	long	min;
	int		i;
	int		nb_philo;
	long	*lst_instr;

	lst_instr = data->shared.lst_msg;
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
