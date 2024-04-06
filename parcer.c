/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/06 15:19:16 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include "libft/libft.h"
#include "minishell.h"
#include <stdlib.h>


// void lk()
// {
// 	system("leaks minishell");
// }

void	ft_puterror(int p)
{
	if (p == 0)
		ft_putendl_fd("chanbor: syntax error near unexpected token `|'", 2);
	if (p == 1)
		ft_putendl_fd("chanbor: syntax error near unexpected token `>'", 2);
	if (p == 3 || p == 5)
		ft_putendl_fd("chanbor: syntax error near unexpected token `<'", 2);
	if (p == 6)
		ft_putendl_fd("chanbor: syntax error near unexpected token `newline'", 2);
	if (p == 7)
		ft_putendl_fd("chanbor: syntax error near unexpected token `? '", 2);

}
int	main(int ac, char **av, char **env)
{
	int	p;
	char	*str;
	t_minishell *cmp;
	// atexit(lk);
	// while (1)
	// {
		str = readline("chanbor $> ");
		p = ft_checker(str);
		add_history(str);
		ft_puterror(p);
		if (p != -1)
		{
			free(str);
			return (1);
		}
		cmp = parcing(str);
		ft_cleanshell(cmp);
		free(str);

	// }
	return (0);
}
