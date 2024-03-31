/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_linker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 00:40:55 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"
#include <stdio.h>

t_docker	*lst_cmd(char *cmd, char *file, int *arr, int len)
{
	t_docker	*lst;

	lst = malloc(sizeof(t_docker));
	if (!lst)
		return (NULL);
	lst->cmds = ft_splits(cmd, 0);
	lst->afcmd = ft_after_cmd(ft_splits(file, 1));
	lst->files = ft_files(ft_splits(file, 1));
	lst->arr = arr;
	lst->alen = len;
	lst->con = ft_concat(lst->cmds,++lst->afcmd );
	lst->next = 0x0;
	return (lst);
}

t_docker	*last_cmd(t_docker *lst)
{
	t_docker	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstaddfront(t_docker **head, t_docker *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_back_executor(t_docker **head, t_docker *node)
{
	if (!head || !node)
		return ;
	if (*head == NULL)
		lstaddfront(head, node);
	last_cmd(*head)->next = node;
	node->next = NULL;
}

t_docker	*get_link_cmd(char **str, int *b_arr, int len)
{
	t_docker	*head;
	t_docker	*cmd;
	int			lens;
	int			i;
	int			*arr;

	head = 0x0;
	i = 0;
	while (str[i])
	{
		lens = ft_set_tk(str[i]);
		arr = ft_arr_tk(str[i], len);
		if (i < len)
			cmd = lst_cmd(ft_splits(str[i], 1)[0], str[i], arr, lens);
		else
			cmd = lst_cmd(ft_splits(str[i], 1)[0], str[i], arr, lens);
		add_back_executor(&head, cmd);
		i++;
	}
	return (head);
}
