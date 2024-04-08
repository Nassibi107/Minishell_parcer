/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_linker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/08 23:07:52 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"
#include <stdio.h>

t_minishell	*lst_cmd(char *cmd, char *file, int *arr, int len)
{
	t_minishell	*lst;
	char *s;
	char **str;
	char **st1;

	lst = malloc(sizeof(t_minishell));
	if (!lst)
		return (NULL);
	str = ft_splits(file, 1);
	lst->cmdt = ft_splits(cmd, 0);
	lst->afcmd_t = ft_after_cmd(str);
	lst->files = ft_files(str);
	lst->tab = arr;
	lst->len_tab = len;
	s = ft_join(ft_concat(lst->cmdt,++lst->afcmd_t ));
	lst->cmd = ft_splits(s ,0);
	free(s);
	ft_cleantach(str);
	--lst->afcmd_t;
	lst->next = 0x0;
	return (lst);
}

t_minishell	*last_cmd(t_minishell *lst)
{
	t_minishell	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstaddfront(t_minishell **head, t_minishell *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_back_executor(t_minishell **head, t_minishell *node)
{
	if (!head || !node)
		return ;
	if (*head == NULL)
		lstaddfront(head, node);
	last_cmd(*head)->next = node;
	node->next = NULL;
}

t_minishell	*get_link_cmd(char **str)
{
	t_minishell	*head;
	t_minishell	*cmd;
	int			lens;
	int			i;
	int			*arr;
	char **pt;

	head = 0x0;
	i = 0;
	while (str[i])
	{
		lens = ft_set_tk(str[i]);
		arr = ft_arr_tk(str[i], lens);
		pt = ft_splits(str[i], 1);
		if (i < lens)
			cmd = lst_cmd(pt[0] , str[i], arr, lens);
		else
			cmd = lst_cmd(pt[0] , str[i], arr, lens);
		add_back_executor(&head, cmd);
		i++;
		ft_cleantach(pt);
	}
	return (head);
}
