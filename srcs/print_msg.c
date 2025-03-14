/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:10:52 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/14 13:39:17 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void print_time(int time)
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

static void	add_time(int time, char *str)
{
	int	b_time;
	int	l_time;

	b_time = time / 1000;
	l_time = time % 1000;
	ft_custom_itoa(b_time, str);
	ft_strcpy(str + ft_strlen(str), " ");
	ft_custom_itoa(l_time, str + ft_strlen(str));
}

static void	add_id(int id, char *str)
{
	ft_custom_itoa(id, str + ft_strlen(str));
	ft_strcpy(str + ft_strlen(str), " ");
}

static void	add_action(enum e_state state, char *str)
{
	if (state == THINKING)
		ft_strcpy(str + ft_strlen(str), "is thinking");
	else if (state == EATING)
		ft_strcpy(str + ft_strlen(str), "is eating");
	else if (state == SLEEPING)
		ft_strcpy(str + ft_strlen(str), "is sleeping");
	else if (state == DIED)
		ft_strcpy(str + ft_strlen(str), "died");
	else if (state == FORK)
		ft_strcpy(str + ft_strlen(str), "has taken a fork");
	else if (state == END)
		ft_strcpy(str + ft_strlen(str), "end");
}

static void	print_id(int id)
{
	printf("%3d ", id);
}

static void print_action(enum e_state state)
{
	if (state == THINKING)
		printf("is thinking\n");
	else if (state == EATING)
		printf("is eating\n");
	else if (state == SLEEPING)
		printf("is sleeping\n");
	else if (state == DIED)
		printf("died\n");
	else if (state == FORK)
		printf("has taken a fork\n");
	else if (state == END)
		printf("end\n");
	else if (state == TEST)
		printf("Created\n");
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
	print_action(state);
}