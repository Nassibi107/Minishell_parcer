/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/14 11:50:10 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
		printf("\n");

}

int	main(int ac, char **av, char **env)
{
	char	*str;

	while (1)
	{
		str = readline("minishell $> ");
		add_history(str);
		signal(SIGINT, signal_handler);
		parcing(str);
		free (str);
	}
	return (0);
}
