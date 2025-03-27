/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:22:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 17:05:09 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int print_data_init(long **lst_instr, long **lst_last_meal, t_data *data)
{
	int		i;
	*lst_instr = malloc(sizeof(long) * data->nb_philo);
	*lst_last_meal = malloc(sizeof(long) * data->nb_philo);
	if (!*lst_instr || !*lst_last_meal)
		return (MALLOC_FAIL);
	i = -1; 
	while (++i < data->nb_philo)
	{
		(*lst_instr)[i] = -1;
		(*lst_last_meal)[i] = 0;
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

void update_eat(long *lst_last_meal, long min)
{
	int id;

	id = (min & M_ID) >> 48;
	if ((min & M_ACTION) >> 56 == EATING)
		lst_last_meal[id] = (min & M_INST);
}

void	printer(t_data *data)
{
	long	*lst_instr;
	long	*lst_last_meal;
	long	min;
	char	str[100];

	if (print_data_init(&lst_instr, &lst_last_meal, data))
		return ;
	wait_for_begin(&data->start, data);
	while (1)
	{
		print_update(lst_instr, data);
		if (check_starvation(lst_last_meal, data))
			break ;
		min = check_min(lst_instr, data);
		if (min == -1)
			usleep(100);
		else
		{
			gen_str(str, min, data->flag);
			update_eat(lst_last_meal, min);
			write(1, str, ft_strlen(str));
			lst_instr[(min & M_ID) >> 48] = -1;
		}
	}
	end_simulation(data);
}


