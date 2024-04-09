/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/09 00:02:18 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"



t_minishell	*parcing(char *str)
{
	int i;

	t_minishell *cmp;
	t_minishell *tmp;
	t_minishell *head;

	i = 0;
	char **strs = ft_spliter(str);
	cmp = get_link_cmd(strs, head , cmp);
	tmp = cmp;
	while (tmp)
	{
		i = 0;
		printf("\n");
		printf("---------commad:-----------\n");
		while(tmp->cmdt[i])
		{
			printf("cmdt[%i]:%s\n",i,tmp->cmdt[i]);
			i++;
		}
		printf("---------FILES:-----------\n");
		i = 1;
		if (tmp->files)
		{
			while(tmp->files[i])
		{
			printf("file [%i]: %s\n",i,tmp->files[i]);
			i++;
		}
		}
		else
			printf("file [x]: NULL");
		i = 0;
		printf("---------after command:-----------\n");
			while(tmp->afcmd_t[i])
			{
					printf("afcmd_t [%i]: %s\n",i,tmp->afcmd_t[i]);
				i++;
			}
		printf("---------arr[x] :-----------\n");
		i = 0;
		if (tmp->tab)
		{
			while(i  < tmp->len_tab)
			{
				printf("tab [%i]: %i\n",i,tmp->tab[i]);
				i++;
			}
		}
		printf("len : %d\n",tmp->len_tab);
		printf("\n--------------------\n");
		i= 0;
		while(tmp->cmd[i])
			printf("%s\n",tmp->cmd[i++]);
		tmp =  tmp->next;
	}
	ft_cleantach(strs);
	return (cmp);

}
