/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:09:08 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/17 16:19:29 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	build_str(char *str, long time, enum e_state action, t_data *data)
{
	int				id;
	enum e_state	state;

	(void)data;
	str[0] = 0;
	id = data->philo_id;
	state = action;
	if (data->flag)
		add_emoji(state, str);
	if (data->flag)
		add_time(time, str);
	else
		add_vanilla_time(time, str);
	if (data->flag)
		add_color(id, str);
	add_id(id, str);
	add_action(state, str);
	if (data->flag)	
		add_color(-1, str);
	ft_strcat(str, "\n");
}

void	print_death(t_data *data, long time)
{
	char	str[100];

	build_str(str, time, DIED, data);
	sem_wait(data->sem_print);
	write(1, str, ft_strlen(str));
}
