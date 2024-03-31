/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 14:59:38 by ynassibi         ###   ########.fr       */
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
	// while(strs[i])
	// 	printf("%s\n",strs[i++]);
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
		i = 0;
		printf("---------after command:-----------\n");
			while(cmp->afcmd[i])
			{
					printf("afcmd [%i]: %s\n",i,cmp->afcmd[i]);
				i++;
			}
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
		printf("len : %d\n",cmp->alen);
		printf("\n--------------------\n");
		i= 0;
		while(cmp->con[i])
			printf("%s\n",cmp->con[i++]);
		cmp =  cmp->next;
	}
	return (NULL);
}
