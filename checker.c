/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:36:15 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/04 15:09:42 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parcer.h"

int	pip_check(char *str)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	if (str[i] == '|')
		return (1);
	while (str[i])
	{
		if (str[i] == '|' )
		{
			while (str[i] == '|')
			{
				i++;
				t++;
			}
			if (t >= 3)
				return (1);
		}
		i++;
	}
	return (0);
}

int	red_check(char *str)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	while (str[i])
	{
		ft_skep(str, &i);
		if (str[i] == '>')
		{
			while (str[i] == '>')
			{
				if (str[i + 1] == '<')
					return (5);
				i++;
				t++;
			}
			if (t >= 3)
				return (1);
			t = 0;
		}
		i++;
	}
	return (0);
}

int	infile_check(char *str)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	while (str[i])
	{
		ft_skep(str, &i);
		if (str[i] == '<')
		{
			while (str[i] == '<')
			{
				i++;
				t++;
			}
			if (t >= 3)
				return (1);
			t = 0;
		}
		i++;
	}
	return (0);
}

int	check_expected_token(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			i++;
			if (str[i] == '<' || str[i] == '>')
				i++;
			while ((str[i] == 9 || str[i] == 32) && str[i])
				i++;
			if (str[i] == '<' || str[i] == '>' || !str[i])
				return (7);
		}
		i++;
	}
	return (0);
}

int	ft_checker(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '>' || str[i] == '<')
	{
		if (ft_strlen(str) <= 2)
			return (6);
	}
	if (pip_check(str))
		return (0);
	if (red_check(str))
		return (red_check(str));
	if (infile_check(str))
		return (3);
	if (check_expected_token(str))
		return (7);
	return (-1);
}
