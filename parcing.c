/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/08 13:32:02 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include "parcer.h"
#include <stdio.h>

t_minishell	*parcing(char *str)
{
	int i;
	int	*arr ;
	int	len;
	t_minishell *cmp;

	len = ft_set_tk(str);

	i = 0;
	char **strs = ft_spliter(str);

	cmp = get_link_cmd(strs, len);
	ft_cleantach(strs);

	return (cmp);

}
