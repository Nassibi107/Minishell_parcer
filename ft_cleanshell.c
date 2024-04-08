/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:19:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/03 13:57:25 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"


void ft_cleanshell(t_minishell **node)
{
	t_minishell	*temp;
	t_minishell	*current;

	current = *node;
	while (current)
	{
		temp = current->next;
		ft_cleantach(current->cmd);
		ft_cleantach(current->cmdt);
		ft_cleantach(current->files);
		ft_cleantach(current->afcmd_t);
		current = temp;
		//  free(current);
	}
	node = NULL;
}
