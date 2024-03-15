/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:39:04 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/15 16:54:41 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "parcer.h"


void	ft_parq_epur(char *str, int *i,int *len, char f)
{
	int	op;

	op = 0;
	*i += 1;
	*len += 1;
	if (f == 'q')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\"')
				op = 1;
			*i += 1;
			*len +=1;
		}
	}
	else if (f == 's')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\'')
				op = 1;
			*i += 1;
			*len +=1;
		}
	}
}
int ft_strlen_epur(char *str)
{
	int len = 0;
	int i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i]== '\'' || str[i] == '\"')
		{
			if (str[i] == '\'')
			ft_parq_epur(str, &i, &len ,'s');
			else
			ft_parq_epur(str, &i, &len ,'q');
		}
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		if (str[i] == ' ' && !str[i + 1])
			break;
		len++;
		i++;
	}
	return (len);
}
char	*epur_str(char *str)
{
	int	len;
	char	*new;
	int i = 0;
	int op = 0;
	len = ft_strlen_epur(str);
	new = malloc((len + 1));
	if (!new)
		return (0x0);
	while(str[i])
	{
		if (str[i]== '\'' || str[i] == '\"')
		{
			if (str[i] == '\'')
			{
				while ((str[i]) && op == 0)
				{
					new[i]= str[i];
					if (str[i] == '\'')
						op = 1;
					i++;
				}
			}
			else if (str[i] == '\"')
			{
				while ((str[i]) && op == 0)
				{
					new[i] = str[i];
					if (str[i] == '\"')
						op = 1;
					i++;
				}
			}
		}
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		if (str[i] == ' ' && !str[i + 1])
			break;
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
int main (int ac, char **av)
{
	printf("%s\n",epur_str(av[1]));
}
