/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:25:02 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/29 14:44:08 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parcer.h"

char *ft_aftercmd(char *s)
{
	int len;
	char *word;
	int i = 0;
	int q = 0;
	while(s[i] == 9 || s[i] == 32)
		s++;
	is_quot_(s, &q);
	s += q;
	while ((s[i] != 9  && s[i] != 32) && s[i])
		s++;
	len = ft_strlen(s);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}


char	**ft_after_cmd(char **s)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = ft_strldd(s);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = ft_aftercmd(s[id++]);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return(arr);
}
