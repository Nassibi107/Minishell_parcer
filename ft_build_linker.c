/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_linker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/20 12:52:44 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "parcer.h"
#include <stdio.h>

t_docker	*lst_cmd(char *cmd,char *file,int *i)
{
	t_docker	*lst;

	lst = malloc(sizeof(t_docker));
	if (!lst)
		return (NULL);
	lst->cmd = ft_splits(cmd,1)[0];
	lst->cmds = ft_splits(lst->cmd,0);
	lst->tk = NULL;
	lst->files = ft_splits(file,1)[0];
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

t_docker	*get_link_cmd(char **str,int *b_arr,int len)
{
	int	i;
	t_docker	*head;
	t_docker	*cmd;
	int	*id = 0;
	head = 0x0;
	i = 0;
	while(str[i])
	{
		if (i < len)
			cmd = lst_cmd(str[i],str[i],NULL);
		else
			cmd = lst_cmd(str[i],str[i],NULL);
		add_back_executor(&head , cmd);
		i++;
	}
	return (head);
}
