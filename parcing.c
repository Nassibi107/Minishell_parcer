/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/24 14:05:35 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include "parcer.h"
#include <stdio.h>

t_docker	*parcing(char *str)
{
	int i = 0;
	int	*arr ;
	int	len;
	t_docker *cmp;
	len = ft_set_tk(str);
	arr = ft_arr_tk(str, len);

	i = 0;
	char **strs = ft_spliter(str);
	cmp = get_link_cmd(strs,arr,len);
	while (cmp)
	{
		i = 0;
		printf("\n");
		printf("---------commad:-----------\n");
		while(cmp->cmds[i])
		{
			printf("cmds[%i]:%s\n",i,cmp->cmds[i]);
			i++;
		}
		printf("---------FILES:-----------\n");
		i = 1;
		if (cmp->files)
		{
			while(cmp->files[i])
		{
			printf("file [%i]: %s\n",i,cmp->files[i]);
			i++;
		}
		}
		else
			printf("file [x]: NULL");
		i = 1;
		printf("---------after command:-----------\n");
		if (cmp->afcmd)
		{
			while(cmp->afcmd[i])
		{
			if (ft_strlen(cmp->afcmd[i]))
				printf("afcmd [%i]: %s\n",i,cmp->afcmd[i]);
			i++;
		}
		}
		else
			printf("afcmd [x]: NULL");
		printf("---------arr[x] :-----------\n");
		i = 0;
		if (cmp->arr)
		{
			while(i  < cmp->alen)
		{
			printf("arr [%i]: %i\n",i,cmp->arr[i]);
			i++;
		}
		}
		printf("---------len :-----------\n");
		printf("%d",cmp->alen);
		printf("\n--------------------\n");
		cmp =  cmp->next;
	}
	return (NULL);
}
