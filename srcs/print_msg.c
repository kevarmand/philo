/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:10:52 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 16:58:19 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_time(int time)
{
	int	b_time;
	int	l_time;
	int	u_time;
	
	u_time = time % 1000;
	time = time / 1000;
	b_time = (time / 1000) % 1000;
	l_time = time % 1000;
	if (b_time == 0)
		printf("   ");
	else
		printf("%3d", b_time);
	printf(" %03d ", l_time);
	printf("(%03d) ", u_time);
}

void	add_time(int time, char *str)
{
	int	b_time;
	int	l_time;

	b_time = time / 1000;
	l_time = time % 1000;
	ft_custom_itoa(b_time, str + ft_strlen(str));
	ft_strcat(str, " (");
	ft_custom_itoa(l_time, str + ft_strlen(str));
	ft_strcat(str, ") ");
}

void	add_id(int id, char *str)
{
	ft_custom_itoa(id, str + ft_strlen(str));
	ft_strcat(str, " ");
}

void	add_action(enum e_state state, char *str)
{
	if (state == THINKING)
		ft_strcpy(str + ft_strlen(str), "is thinking     ");
	else if (state == EATING)
		ft_strcpy(str + ft_strlen(str), "is eating	     ");
	else if (state == SLEEPING)
		ft_strcpy(str + ft_strlen(str), "is sleeping     ");
	else if (state == DIED)
		ft_strcpy(str + ft_strlen(str), "died            ");
	else if (state == FORK)
		ft_strcpy(str + ft_strlen(str), "has taken a fork");
	else if (state == END)
		ft_strcpy(str + ft_strlen(str), "end");
}

void	print_id(int id)
{
	printf("%3d ", id);
}


void	print_msg(enum e_state state, int id, int time)
{
	char str[100];

	str[0] = 0;
	// add_time(time, str);
	// add_id(id, str);
	// add_action(state, str);
	//proteger le mutex ici. ( on fait un seul write)
	
	print_time(time);
	print_id(id);
	//print_action(state);
}

void	add_color(int id, char *str)
{
	if (id == 0)
		ft_strcat(str, CYAN);
	else if (id == 1)
		ft_strcat(str, GREEN);
	else if (id == 2)
		ft_strcat(str, YELLOW);
	else if (id == 3)
		ft_strcat(str, BLUE);
	else if (id == 4)
		ft_strcat(str, MAGENTA);
	else if (id == 5)
		ft_strcat(str, CYAN);
	else if (id == 6)
		ft_strcat(str, GREEN);
	else if (id == 7)
		ft_strcat(str, YELLOW);
	else if (id == 8)
		ft_strcat(str, BLUE);
	else if (id == 9)
		ft_strcat(str, MAGENTA);
	else
		ft_strcat(str, RESET);
}

void	add_emoji(enum e_state state, char *str)
{
	if (state == THINKING)
		ft_strcat(str, "🤔 ");
	else if (state == EATING)
		ft_strcat(str, "🍝 ");
	else if (state == SLEEPING)
		ft_strcat(str, "😴 ");
	else if (state == DIED)
		ft_strcat(str, "💀 ");
	else if (state == FORK)
		ft_strcat(str, "🍴 ");
	else if (state == END)
		ft_strcat(str, "🏁 ");
	else if (state == TEST)
		ft_strcat(str, "🎉 ");
}

void	print_advanced(t_philo *philo, enum e_state state, int time)
{
	char *str;

	str = philo->str;
	str[0] = 0;
	if (philo->data->flag)
	{
		add_emoji(state, str);
		add_color(philo->id, str);
	}
	add_time(time, str);
	add_id(philo->id, str);
	add_action(state, str);
	if (philo->data->flag)
		add_color(-1, str);
	ft_strcat(str, "\n");
	pthread_mutex_lock(&philo->data->talking_stick);
	if (is_sim_running(philo->data))
		write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&philo->data->talking_stick);
}

void	annonce_action(t_philo *philo, enum e_state state, struct timeval *now)
{
	long time;

	time = get_time_diff(&philo->data->start, now);
	gen_msg(philo, state, time);
}