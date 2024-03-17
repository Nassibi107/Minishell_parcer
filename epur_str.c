/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:39:04 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/17 14:46:30 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "parcer.h"
#include <stdio.h>

static int	get_des(char c)
{
	if ( c == '\t' || c == ' ')
		return (1);
	return (0);
}
void	hun_pars(char *s1, int *id, int *i, char *word)
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
static char	**handle_of_malloc(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	number_of_words(char *str, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			wc++;
			if (str[i] == '\'' || str[i] == '\"')
			{
				if(str[i] == '\'')
				{
					i++;
					while(str[i] != '\'')
						i++;
				}
				else if(str[i] == '\"')
				{
					i++;
					while(str[i] != '\"')
						i++;
				}
			}
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (wc);
}
//yassine@nassibi@1337
char	*hudler_t(char *s1, char *word, int *id)
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
				hun_pars(s1, id, &i, word);
				op = 0;
			}
		}
		word[i++] = s1[(*id)++];
	}
	word[i] = '\0';
	return (word);
}
static char	*hooks(char *s1, int *id, char c)
{
	char	*word;
	size_t	len_word;
	int		i;

	len_word = 0;
	while (s1[*id] == c)
		(*id)++;
	i = *id;
	while (s1[i])
	{
		if (s1[i] == '\'' || s1[i] == '\"')
		{
			if (s1[i] == '\"' )
				 ft_parq(s1, &i, 'q');
			else if (s1[i] == '\'')
					ft_parq(s1, &i, 's');
			len_word += i;
		}
		else if(s1[i] != c)
		{
			i++;
			len_word++;
		}
		else
			break;
	}
	printf("» %ld\n",len_word);
	word = malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);

	return (hudler_t(s1, word, id));
}

char	**ft_splits(char *s, char c)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = number_of_words(s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = hooks(s, &id, c);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return(arr);
}


int main (int ac ,char **av)
{
	int i;

	i = 0;

	char **strs = ft_splits("echo \"yassine 13\"     \'ls\'"       , ' ');
	while (strs[i])
	{
		printf("%s\n",strs[i]);
		i++;
	}
}
