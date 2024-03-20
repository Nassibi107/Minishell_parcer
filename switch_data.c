/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:20:41 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/19 15:50:51 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"
#include <stdio.h>


int	get_numofard(int *arr, int len)
{
	int	cn;
	int	i;

	i = 0;
	cn = 0;
	while(i  < len)
	{
		if (arr[i] == 0)
			cn++;
		i++;
	}
	return (cn + 1);
}
t_minishell	*get_data(t_docker *cmp,int *arr,int len)
{
	int	len_ar;
	int	bg = 1;
	t_minishell *shell;
	t_minishell *head;

	head = 0x0;
	len_ar = get_numofard(arr,len);
	int  i = 0;

	while (len_ar )
	{
		shell = new_shell(cmp->cmd, NULL, NULL,0);
		if(cmp->tk != 0 ||cmp->tk != -1 )
		{
			shell->after_out_or_input = cmp->cmd;
			printf("%d\n",cmp->tk);
			cmp = cmp->next;
		}
		shell_at_back(&head, shell);
		len_ar--;
	}
	return (head);
}
