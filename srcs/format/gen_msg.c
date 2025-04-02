/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:09:08 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 17:23:53 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	build_str(char *str, long instr, int flag, t_data *data)
{
	int				id;
	int				time;
	enum e_state	state;

	(void)data;
	str[0] = 0;
	id = (instr & M_ID) >> 48;
	time = instr & M_TIME;
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

long 	encode_msg(long id, enum e_state state, long time)
{
	long	msg;

	msg = (long)state;
	msg = (msg << 56);
	msg += (id << 48);
	msg += (long)time;
	return (msg);
}

/***
 * @brief print the message without the buffer
 * 
 * //generate the message
 * //print the message
 */
void	printf_philo_die(int id, long time, int flag)
{
	long	msg;
	char	str[100];

	msg = encode_msg(id, DIED, time);
	build_str(str, msg, flag, NULL);
	printf("%s", str);
}