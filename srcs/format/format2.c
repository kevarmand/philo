/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:22:10 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 10:23:29 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_time(int time, char *str)
{
	int	ms_time;
	int	s_time;
	int	m_time;

	ms_time = time / 1000;
	s_time = ms_time / 1000;
	m_time = s_time / 60;
	ms_time = ms_time % 1000;
	s_time = s_time % 60;
	if (m_time == 0)
		ft_strcat(str, "   ");
	else
	{
		ft_custom_itoa(m_time, str + ft_strlen(str));
		ft_strcat(str, ":");
	}
	if (s_time < 10)
		ft_strcat(str, " ");
	ft_custom_itoa(s_time, str + ft_strlen(str));
	ft_strcat(str, ".");
	if (ms_time < 100)
		ft_strcat(str, "0");
	if (ms_time < 10)
		ft_strcat(str, "0");
	ft_custom_itoa(ms_time, str + ft_strlen(str));
}

void	add_vanilla_time(long time, char *str)
{
	int	ms_time;

	ms_time = (int)(time / 1000);
	if (ms_time < 1000)
		ft_strcat(str, " ");
	if (ms_time < 10000)
		ft_strcat(str, " ");
	ft_custom_itoa(ms_time, str + ft_strlen(str));
}
