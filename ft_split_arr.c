/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:54 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/24 14:17:01 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"
#include <stdio.h>
#include <stdlib.h>


int	*ft_split_arr(int *b_arr , int alen, int *i, int *arr_len)
{

	int ii = 0;
	int	*arr;
	int	len;
	int	t = *i;

	len = 0;

	while(*i < (alen))
	{
		if (b_arr[*i] == 0)
			break;
		(*i)++;
		len++;
	}
	arr = malloc(sizeof(int) * len );
	while (ii  <len)
	{
		arr[ii] = b_arr[t];
		t++;
		ii++;
	}
	(*i)++;
	*arr_len = len;
	return (arr);
}

