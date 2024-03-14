/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_linker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/14 12:20:52 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"


static void	ft_lstadd_back_sa(t_node **sa, t_node *nsa)
{
	t_node	*temp;

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

static t_node	*ft_lstnew_sa(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->cmd = NULL;
   new->tk = -1;
	new->next = NULL;
	return (new);
}

void	ft_build_sa(char **str, t_node **sa)
{
	int	i;
	int	val;

	i = 0;
	while (str[i])
	{

	}
}
