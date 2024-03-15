/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_linker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/14 15:47:44 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include "parcer.h"


static t_minishell	*lststack(t_minishell *lst)
{
	t_minishell	*temp;

	if (!lst)
		return (0x0);
	temp = lst;
	if (!temp)
		return (0);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
static void	ft_lstadd_back_sa(t_minishell **sa, t_minishell *nsa)
{
	t_minishell	*temp;

	if (!*sa)
	{
		if (!nsa)
			return ;
		*sa = nsa;
		return ;
	}
	temp = lststack(*sa);
	temp->next = nsa;
}

static t_minishell	*ft_lstnew_sa(char *str, int *sub_arr, int len , char **afc)
{
	t_minishell	*new;

	new = malloc(sizeof(t_minishell));
	if (!new)
		return (NULL);
	new->cmd = ft_split(str, ' ');
	new->flag_input_output = ft_sub_ara(sub_arr);
	new->len_tab_flaged = len;
	new->after_out_or_input = ;
	return (new);
}

void	ft_build_sa(char **str, t_minishell *cmp)
{
	int	i;
	int	val;

	i = 0;
	while (str[i])
	{
		if (!cmp)
		{
			ft_lstnew_sa(ft_split(str[i], ' '), 0,
			)
		}
		else {

		}

	}
}
