/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:06:43 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/09 15:54:50 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include <stdlib.h>

void	errq(int op)
{
	if (!op)
	{
		ft_putendl_fd("bash: syntax error near `'\"", 2);
		exit(1);
	}
	return ;
}

void	hudler_o(char *s1, int i, int *op, size_t *len_word)
{
	while (s1[i])
	{
		if (s1[i] == '\"' || s1[i] == '\'')
		{
			if (!(*op))
			{
				if (s1[i] == '\"' )
					*op = ft_parq(s1, &i, 'q');
				else if (s1[i] == '\'')
					*op = ft_parq(s1, &i, 's');
			}
			errq(*op);
			*op = 0;
			*len_word += i;
		}
		else if (!ft_vtk(s1[i]))
		{
			(*len_word)++;
			i++;
		}
		else
			return ;
	}
}

void	hun_par(char *s1, int *id, int *i, char *word)
{
	int	op;

	op = 0;
	if (s1[*id] == '\"' )
	{
		while (s1[*id] && op == 0)
		{
			word[(*i)++] = s1[(*id)++];
			if (s1[*id] == '\"')
				op = 1;
		}
	}
	else if (s1[*id] == '\'' )
	{
		while (s1[*id] && op == 0)
		{
			word[(*i)++] = s1[(*id)++];
			if (s1[*id] == '\'')
				op = 1;
		}
	}
}

char	*hudler_t(char *s1, char *word, int *id)
{
	int	i;
	int	op;

	i = 0;
	op = 0;
	word[i++] = ' ';
	while (s1[*id] && (!ft_vtk(s1[*id])))
	{
		if (s1[*id] == '\'' || s1[*id] == '\"')
		{
			if (!op)
			{
				hun_par(s1, id, &i, word);
				op = 0;
			}
		}
		word[i++] = s1[(*id)++];
	}
	word[i] = '\0';
	return (word);
}

void	ft_skep(char *str, int *i)
{
	int	op;

	op = 0;
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		if (str[*i] == '\'')
			op = ft_parq(str, i, 's');
		else if (str[*i] == '\"')
			op = ft_parq(str, i, 'q');
		op = 0;
	}
}
