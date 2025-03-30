/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:22:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/30 11:58:41 by marvin           ###   ########.fr       */
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

static void wait_for_begin(struct timeval *start)
{
	struct timeval	now;
	long			time;

	gettimeofday(&now, NULL);
	time = get_time_diff(&now, start);
	precise_sleep(&now, time);
}

void update_eat(long *lst_last_meal, long min)
{
	long	id;
	long	action;

	id = (min & M_ID) >> 48;
	action = (min & M_ACTION) >> 56;
	//check si le philo est deja mort mais besoin dune variable en plus

	if (action == EATING)
	{
		lst_last_meal[id] = (min & M_INST);
	}
	if (action == END)
		lst_last_meal[id] = -1;
}

int		all_philo_ate(long *lst_last_meal, long nb_philo)
{
	long	i;

	i = -1;
	while (++i < nb_philo)
	{
		if (lst_last_meal[i] != -1)
			return (0);
	}
	return (1);
}

void	*printer(void *data1)
{
	t_data	*data;
	long	*lst_instr;
	long	*lst_last_meal;
	long	min;
	char	str[100];

	data = (t_data *)data1;
	if (print_data_init(&lst_instr, &lst_last_meal, data))
		return (NULL);
	wait_for_begin(&data->start);
	while (1)
	{
		print_update(lst_instr, data);
		min = check_min(lst_instr, data);
		if (min == -1)
		{
			if (check_starvation(lst_last_meal, data))
				break ;
			if (all_philo_ate(lst_last_meal, data->nb_philo))
				break ;
			usleep(100);
		}
		else
		{
			gen_str(str, min, data->flag, data);
			update_eat(lst_last_meal, min);
			write(1, str, ft_strlen(str));
			lst_instr[(min & M_ID) >> 48] = -1;
		}
	}
	end_simulation(data);
	free(lst_instr);
	free(lst_last_meal);
	return (NULL);
}
