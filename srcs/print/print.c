/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:22:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:10 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printer(t_data *data)
{
	long	*lst_instr;
	long	min;
	char	str[100];

	//init lst_instr
	while (1)
	{
		print_update(lst_instr, data);
		min = check_min(lst_instr, data);
		if (min == -1)
			sleep(10);
		else
		{
			gen_str(str, min);
			if(!sim_is_running(data))
				break ;
			write(1, str, ft_strlen(str));
			lst_instr[(min & M_ID) >> 40] = -1;//atention au mutex
		}
	}
	//faire des trucs (sim is no running)
}