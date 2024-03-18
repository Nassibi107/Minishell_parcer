/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/18 17:28:33 by ynassibi         ###   ########.fr       */
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
	cmp = get_link_cmd(strs,arr);
	while (cmp)
	{
		i = 0;
		printf("--------------------\n");
		while(cmp->cmd[i])
		{
			printf("cmd[%i]:%s\n",i,cmp->cmd[i]);

			i++;
		}
		printf("\n");
		printf("token: %i\n",cmp->tk);
		printf("--------------------\n");
		cmp =  cmp->next;
	}
	return (NULL);
}
