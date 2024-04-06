/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:39:04 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/06 14:59:07 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include <stdlib.h>

int	get_des(char c, int fg)
{
	if (fg == 1)
	{
		if (c == '>' || c == '<')
			return (1);
	}
	else
		if (c == '\t' || c == ' ')
			return (1);
	return (0);
}

static int	number_of_words(char *str, int fg)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (get_des(str[i], fg))
			i++;
		else
		{
			wc++;
			is_quot_(str, &i);
			while (!get_des(str[i], fg) && str[i])
				i++;
		}
	}
	return (wc);
}

char	*hudler_ts(char *s1, char *word, int *id, int fg)
{
	int	i;
	int	op;

	i = 0;
	op = 0;
	while (s1[*id] && (!get_des(s1[*id], fg)))
	{
		if (s1[*id] == '\'' || s1[*id] == '\"')
		{
			if (!op)
			{
				hund(s1, id, &i, word);
				op = 0;
			}
		}
		word[i++] = s1[(*id)++];
	}
	word[i] = '\0';
	return (word);
}

static char	*hooks(char *s1, int *id, int fg)
{
	char	*word;
	size_t	len_word;
	int		i;

	len_word = 0;
	while (get_des(s1[*id], fg))
		(*id)++;
	i = *id;
	ft_get_len(s1, i, &len_word, fg);
	word = malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	return (hudler_ts(s1, word, id, fg));
}

char	**ft_splits(char *s, char fg)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = number_of_words(s, fg);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = hooks(s, &id, fg);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
