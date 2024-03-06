/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:09:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/06 15:10:06 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int ac, char **av, char **env)
{
	char *str;

	while (1)
	{
		str = readline("minishell $> ");
		// return = parsing(str);
		// executor(return);
		printf("%s\n", str);
		free (str);
	}
	return (0);
}
