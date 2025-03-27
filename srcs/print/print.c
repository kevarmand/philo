/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:22:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 13:16:32 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int print_data_init(long **lst_instr, long **lst_dead, t_data *data)
{
	int		i;
	*lst_instr = malloc(sizeof(long) * data->nb_philo);
	*lst_dead = malloc(sizeof(long) * data->nb_philo);
	if (!*lst_instr || !*lst_dead)
		return (MALLOC_FAIL);
	i = -1; 
	while (++i < data->nb_philo)
	{
		(*lst_instr)[i] = -1;
		(*lst_dead)[i] = -1;
	}
	return (0);
}

static void wait_for_begin(struct timeval *start, t_data *data)
{
	struct timeval	now;
	long			time;

	gettimeofday(&now, NULL);
	time = get_time_diff(&now, start);
	precise_sleep(&now, time);
}

void	printer(t_data *data)
{
	long	*lst_instr;
	long	*lst_dead;
	long	min;
	char	str[100];

	if (print_data_init(&lst_instr, &lst_dead, data))
		return ;
	wait_for_begin(&data->start, data);
	while (1)
	{
		print_update(lst_instr, data);
		min = check_min(lst_instr, data);
		if (min == -1)
			usleep(100);
		else
		{
			gen_str(str, min, data->flag);//Ici on checkera le mesage mort
			if (!sim_is_running(data))
				break ;
			write(1, str, ft_strlen(str));
			lst_instr[(min & M_ID) >> 48] = -1;
		}
	}
	printf("end_monitoring\n");
	//faire des trucs (sim is no running)
	//genre kill propre;et
}
