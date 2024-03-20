/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcfun_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:07:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/19 22:47:40 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include <stdlib.h>

int	ft_vtk(char c)
{
	if (c == '|')
		return (1);
	return (0);
}


static void	case_one(int *arr, char c, int *i, int *j)
{
	if (c == '<')
	{
		arr[*j] = 4;
		*j += 1;
	}
	else
	{
		arr[*j] = 3;
		*j += 1;
	}
	*i += 1;
}

static void	case_two(int *arr, char c, int *i, int *j)
{
	if (c == '>')
	{
		arr[*j] = 2;
		*j += 1;
	}
	else
	{
		arr[*j] = 1;
		*j += 1;
	}
	*i += 1;
}

int	*ft_arr_tk(char *str, int len)
{
	int	*arr;
	int	i;
	int	j;
	int	op;

	arr = malloc(len * sizeof(int));
	i = 0;
	j = 0;
	while (str[i] && j < len)
	{
		ft_skep (str, &i);
		if (str[i] == '|')
			arr[j++] = 0;
		else if (str[i] == '<')
			case_one(arr, str[i + 1], &i, &j);
		else if (str[i] == '>')
			case_two(arr, str[i + 1], &i, &j);
		i++;
	}
	return (arr);
}

void fun (char *str,int *i)
{
	int	op;

	op = 0;
	while (!ft_vtk(str[*i]) && str[*i])
	{
		if (str[*i] == '\"' || str[*i] == '\'')
		{
			if (!op)
			{
				if (str[*i] == '\"' )
					op = ft_parq(str, i, 'q');
				else if (str[*i] == '\'')
					op = ft_parq(str, i, 's');
			}
			op = 0;
		}
		(*i)++;
	}
}

int	number_of_word(char *str)
{
	int	i;
	int	wc;
	int	*arr;

	i = 0;
	wc = 0;

	while (str[i])
	{
		if (ft_vtk(str[i]))
			i++;
		else
		{
			wc++;
			fun(str,&i);
		}
	}
	return (wc);
}
