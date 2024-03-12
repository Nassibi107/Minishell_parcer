/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcfun_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:21:56 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/12 15:20:24 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include <stdio.h>

static char	**handle_of_malloc(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}
static char	*hook(char *s1, int *id)
{
	char	*word;
	size_t	len_word;
	int		i;
	int op = 0;
	len_word = 0;
	i = 0;

	while (ft_vtk(s1[*id]))
		(*id)++;
	i = *id;
	hudler_o(s1, i, &op, &len_word);
	word = malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	return (hudler_t(s1,word,id));
}
char	**ft_spliter(char *s)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = number_of_word(s);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = hook(s, &id);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
