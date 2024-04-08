/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/03 13:57:17 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include "parcer.h"
#include <stdio.h>

t_minishell	*parcing(char *str)
{
	int i = 0;
	int	*arr ;
	int	len;
	t_minishell *cmp;



	len = ft_set_tk(str);
	arr = ft_arr_tk(str, len);

	i = 0;
	char **strs = ft_spliter(str);

	// while(strs[i])
	// 	printf("%s\n",strs[i++]);
	cmp = get_link_cmd(strs, len);
	while (cmp)
	{
		i = 0;
		printf("\n");
		printf("---------commad:-----------\n");
		while(cmp->cmdt[i])
		{
			printf("cmdt[%i]:%s\n",i,cmp->cmdt[i]);
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
			while(cmp->afcmd_t[i])
			{
					printf("afcmd_t [%i]: %s\n",i,cmp->afcmd_t[i]);
				i++;
			}
		printf("---------arr[x] :-----------\n");
		i = 0;
		if (cmp->tab)
		{
			while(i  < cmp->len_tab)
			{
				printf("tab [%i]: %i\n",i,cmp->tab[i]);
				i++;
			}
		}
		printf("len : %d\n",cmp->len_tab);
		printf("\n--------------------\n");
		i= 0;
		while(cmp->cmd[i])
			printf("%s\n",cmp->cmd[i++]);
		cmp =  cmp->next;
	}
	return (cmp);

}
