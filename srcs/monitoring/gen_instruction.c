/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:09:08 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/31 11:26:39 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	gen_str(char *str, long instr, int flag, t_data *data)
{
	int		id;
	int		time;
	enum e_state	state;

	(void)data;
	str[0] = 0;
	id = (instr & M_ID) >> 48;
	time = instr & M_INST;
	state = (instr & M_ACTION) >> 56;
	if (flag)
		add_emoji(state, str);
	if (flag)
		add_time(time, str);
	else
		add_vanilla_time(time, str);
	if (flag)
		add_color(id, str);
	add_id(id, str);
	add_action(state, str);
	if (flag)
		add_color(-1, str);
	ft_strcat(str, "\n");
}

void	gen_msg(t_philo *philo, enum e_state state, long time)
{
	long	msg;

	msg = (long)state;
	msg = (msg << 56);
	msg += ((long)(philo->id) << 48);
	msg += (long)time;
	print_add(philo->data->tab_queue + philo->id, msg);
}
