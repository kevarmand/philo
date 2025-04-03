/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:44:04 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 14:25:29 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	usage_msg(void);
static void	usage_msg2(void);

int	error_msg(enum e_error err)
{
	printf(RED);
	if (err == WRONG_NB_ARG)
		printf("Error: wrong number of arguments\n\n");
	else if (err == WRONG_ARG)
		printf("Error: wrong arguments\n\n");
	else if (err == ERROR_LOGICAL)
	{
		printf("Une peu de bon sens, voyons !\n");
		printf("Un philosophe ne peut pas mourrir en mageant\n");
	}
	else if (err == ERROR_MEAL)
		printf("Error: wrong number of meals\n\n");
	else if (err == ERROR_TIME)
		printf("timer must : 60ms < time < INT_MAX\n\n");
	else if (err == ERROR_NB)
		printf("number of philosopher must be between 1 and 200\n\n");
	usage_msg();
	usage_msg2();
	return (err);
}

static void	usage_msg(void)
{
	printf(RESET);
	printf(BOLD);
	printf("./philo");
	printf(RESET);
	printf("  [");
	printf(CYAN);
	printf("number_of_philosopher");
	printf(RESET);
	printf("] [");
	printf(GREEN);
	printf("time_to_die");
	printf(RESET);
	printf("] [");
	printf(YELLOW);
	printf("time_to_eat");
	printf(RESET);
	printf("] [");
	printf(BLUE);
	printf("time_to_sleep");
	printf(RESET);
	printf("] {");
	printf(MAGENTA);
	printf("number_of_time_each_philosophers_must_eat");
	printf(RESET);
	printf("}\n");
}

static void	usage_msg2(void)
{
	printf("\n%s%snumber_of_philosopher :\n    %s➡️ ", CYAN, BOLD, RESET);
	printf(" number of philosopher (and forks)\n    ➡️  INTEGER [1-200]\n\n");
	printf("%s%stime_to_die :\n    %s➡️ ", GREEN, BOLD, RESET);
	printf(" time in milliseconds before a philosopher dies\n    ➡️");
	printf("  INTEGER [1-INT_MAX]\n\n");
	printf("%s%stime_to_eat :\n    %s➡️ ", YELLOW, BOLD, RESET);
	printf(" time in milliseconds it takes for a philosopher to eat\n    ➡️");
	printf("  INTEGER [1-INT_MAX]\n\n");
	printf("%s%stime_to_sleep :\n    %s➡️ ", BLUE, BOLD, RESET);
	printf(" time in milliseconds it takes for a philosopher to sleep\n    ➡️");
	printf("  INTEGER [1-INT_MAX]\n\n");
	printf("%s%snumber_of_time_each_philosophers_must_eat : ", MAGENTA, BOLD);
	printf("ptional)\n    %s➡️ ", RESET);
	printf(" number of time each philosopher must eat\n    ➡️");
	printf("  INTEGER [1-INT_MAX]\n\n");
}
