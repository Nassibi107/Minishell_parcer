/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:54 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/23 15:37:00 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include <stdio.h>
#include <stdlib.h>


int	*ft_split_arr(int *b_arr , int alen, int *i)
{

	int ii = 0;
	int	*arr;
	int	len;
	int	t = *i;
	len = 0;
	while(b_arr[*i] && *i < alen)
	{
		if (b_arr[*i] == 0)
			break;
		(*i)++;
		len++;
	}
	arr = malloc(4 * len);
	while (b_arr[t])
	{
		arr[ii] = b_arr[t++];
		ii++;
	}
	(*i)++;
	t = 0;

	return (arr);
}

