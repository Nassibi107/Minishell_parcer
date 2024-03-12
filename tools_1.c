/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:06:43 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/12 15:24:29 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"


void hudler_o(char *s1,int i,int *op,size_t *len_word)
{
	while (s1[i])
	{
		if(s1[i] == '\"' || s1[i] == '\'')
		{
			if (!(*op))
			{
				if (s1[i] == '\"' )
					*op	= ft_parq(s1, &i,'q');
				else if( s1[i] == '\'')
					*op = ft_parq(s1, &i,'s');
			}
			if (!(*op))
				exit(1);
			*op = 0;
			*len_word += i;
		}
		else if (!ft_vtk(s1[i]))
		{
			(*len_word)++;
			i++;
		}
		else
			return;
	}
}

void  hun_par(char *s1,int *id, int *i ,char *word)
{
	int op = 0;
	if (s1[*id] == '\"' )
	{
		while(s1[*id] && op == 0)
		{
			word[(*i)++] = s1[(*id)++];
			if (s1[*id] == '\"')
				op = 1;
		}
	}
	else if (s1[*id] == '\'' )
	{
		while(s1[*id] && op == 0)
		{
			word[(*i)++] = s1[(*id)++];
			if (s1[*id] == '\'')
				op = 1;
		}
	}
}
char  *hudler_t(char *s1,char *word, int *id)
{
	int i;
	int op;

	i = 0;
	op = 0;
	while (s1[*id] && (!ft_vtk(s1[*id])))
	{
		if(s1[*id] == '\'' || s1[*id] == '\"')
		{
			if (!op)
			{
				hun_par(s1,id,&i,word);
				op = 0;
			}
		}
		word[i++] = s1[(*id)++];
	}
	word[i] = '\0';
	return(word);
}
