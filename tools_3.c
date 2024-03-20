/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:47:23 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/19 14:36:42 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

t_minishell	*new_shell(char **cmd,char **atcmd ,int *arr,int len )
{
	t_minishell	*lst;

	lst = malloc(sizeof(t_minishell));
	if (!lst)
		return (NULL);
	lst->cmd = cmd;
	lst->flag_input_output = arr ;
	lst->len_tab_flaged = len;
	lst->after_out_or_input = atcmd ;
	lst->next = 0x0;
	return (lst);
}

int    lst_size_executor(t_minishell **head)
{
    int        i;
    t_minishell    *tmp;

    i = 0;
    tmp = *head;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

t_minishell	*last_shell(t_minishell *lst)
{
	t_minishell	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	shell_at_font(t_minishell **head, t_minishell *node)
{
	node->next = (*head);
	(*head) = node;
}

void	shell_at_back(t_minishell **head, t_minishell *node)
{
    if (!head || !node)
        return ;
    if (*head == NULL)
        shell_at_font(head, node);
    last_shell(*head)->next = node;
    node->next = NULL;
}

// t_minishell	*get_shell(char **str)
// {
// 	int	i;
// 	t_minishell	*head;
// 	t_minishell	*shell;
// 	head = 0x0;
// 	i = 0;

// 	shell = shell_at_back(head, t_minishell *node)
// 	return (head);
// }
