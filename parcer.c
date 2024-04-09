/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/09 15:43:42 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include "libft/libft.h"
#include "minishell.h"
#include <stdlib.h>

void	ft_puterror(int p)
{
	if (p == 0)
		ft_putendl_fd("bash: syntax error near unexpected token `|'", 2);
	if (p == 1)
		ft_putendl_fd("bash: syntax error near unexpected token `>'", 2);
	if (p == 3 || p == 5)
		ft_putendl_fd("bash: syntax error near unexpected token `<'", 2);
	if (p == 6)
		ft_putendl_fd("bash: syntax error near unexpected token `newline'", 2);
	if (p == 7)
		ft_putendl_fd("bash: syntax error near unexpected token `? '", 2);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*head;
	int			p;
	char		*str;

	(void) ac;
	(void) av;
	(void) env;
	while (1)
	{
		str = readline("minishell $> ");
		p = ft_checker(str);
		add_history(str);
		ft_puterror(p);
		if (p != -1)
		{
			free(str);
			exit(1);
		}
		head = parcing(str);
		free(str);
		str = NULL;
	}
	ft_cleanshell(&head);
	return (0);
}
