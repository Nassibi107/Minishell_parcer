/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:09:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/13 13:56:38 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>


int main(int ac, char **av, char **env)
{
	char *str;

	while (1)
	{
		str = readline("minishell $> ");
		// return = parsing(str);
		// executor(return);
		t_node *rst;
		 rst = parcer(str);
		
		free (str);
	}
	return (0);
}
