/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:28:55 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 15:15:21 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_last_meal(t_data *data, long *lst_last_meal, long min);
static void	update_last_meal(long *lst_last_meal, long min);

int	display_event(t_data *data, char *str, long min)
{
	long	*lst_msg;
	long	*lst_last_meal;

	lst_msg = data->shared.lst_msg;
	lst_last_meal = data->shared.lst_last_meal;
	if (check_last_meal(data, lst_last_meal, min))
		return (1);
	update_last_meal(lst_last_meal, min);
	build_str(str, min, data->flag, data);
	write(1, str, ft_strlen(str));
	lst_msg[(min & M_ID) >> 48] = -1;
	return (0);
}

static int	check_last_meal(t_data *data, long *lst_last_meal, long min)
{
	long	id;
	long	time;

	id = (min & M_ID) >> 48;
	time = (min & M_TIME);
	if (time - lst_last_meal[id] >= data->time_to_die)
	{
		printf("%5.3ld %ld died\n", time, id + 1);
		return (1);
	}
	return (0);
}

static void update_last_meal(long *lst_last_meal, long min)
{
	long	id;
	long	action;

	id = (min & M_ID) >> 48;
	action = (min & M_ACTION) >> 56;
	if (action == EATING)
		lst_last_meal[id] = (min & M_TIME);
	if (action == END)
		lst_last_meal[id] = -1;
}
