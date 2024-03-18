/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:39:04 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/17 16:47:44 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include <stdio.h>

int	get_des(char c)
{
	if ( c == '\t' || c == ' ')
		return (1);
	return (0);
}

static int	number_of_words(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (get_des(str[i]))
			i++;
		else
		{
			wc++;
			is_quot_(str,&i);
			while (!get_des(str[i]) && str[i])
				i++;
		}
	}
	return (wc);
}
char	*hudler_ts(char *s1, char *word, int *id)
{
	int	i;
	int	op;

	i = 0;
	op = 0;
	while (s1[*id] && (!get_des(s1[*id])))
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
static char	*hooks(char *s1, int *id)
{
	char	*word;
	size_t	len_word;
	int		i;

	len_word = 0;
	while (get_des(s1[*id]))
		(*id)++;
	i = *id;
	ft_get_len(s1,i,&len_word);
	word = malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	return (hudler_ts(s1, word, id));
}

char	**ft_splits(char *s)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = number_of_words(s);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = hooks(s, &id);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return(arr);
}


// int main (int ac ,char **av)
// {
// 	int i;

// 	i = 0;

// 	char **strs = ft_splits("echo \"yassine 13\"     \'ls\' \'\"ssssss\"\' \'\'");
// 	while (strs[i])
// 	{
// 		printf("%s\n",strs[i]);
// 		i++;
// 	}
// }
