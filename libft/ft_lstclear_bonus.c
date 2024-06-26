/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:54:46 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/03 13:57:57 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		i;
	t_list	*poiter;
	t_list	*temp;

	if (!del || !lst)
		return ;
	i = ft_lstsize(*lst);
	poiter = *lst;
	while (i > 0)
	{
		temp = poiter->next;
		(*del)(poiter->content);
		// free(poiter);
		poiter = temp;
		i--;
	}
	*lst = NULL;
}
