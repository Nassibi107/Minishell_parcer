/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/08 20:39:47 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parcer.h"
#include <stdio.h>

t_node	*parcing(char *str)
{
	int i = 0;
	int	*arr ;
	int	len;

	len = ft_set_tk(str);
	arr = ft_arr_tk(str, len);

	// while (i < len)
	// 	printf(">> %d \t",arr[i++]);
	// i = 0;
	// char **strs = ft_spliter(str);
	// while (strs[i])
	// 	printf("%s\n",strs[i++]);
	printf("%d", number_of_word(str));
	return (NULL);
}
