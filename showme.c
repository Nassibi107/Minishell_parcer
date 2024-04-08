/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:23:26 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/08 13:23:30 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
