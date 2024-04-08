/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/08 17:01:16 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"



t_minishell	*parcing(char *str)
{
	int i;
	int	*arr ;
	int	len;
	t_minishell *cmp;

	i = 0;
	char **strs = ft_spliter(str);

	cmp = get_link_cmd(strs);
	ft_cleantach(strs);
	return (cmp);

}
