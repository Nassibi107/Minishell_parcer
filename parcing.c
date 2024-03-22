/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/22 16:43:29 by ynassibi         ###   ########.fr       */
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
		while(cmp->cmds[i])
		{
			printf("cmds[%i]:%s\n",i,cmp->cmds[i]);
			i++;
		}
		printf("--------------------\n");
		i = 1;
		if (cmp->files)
		{
			while(cmp->files[i])
		{
			printf("file [%i]: %s\n",i,cmp->files[i]);
			i++;
		}
		}
		printf("--------------------\n");
		cmp =  cmp->next;
	}
	return (NULL);
}
