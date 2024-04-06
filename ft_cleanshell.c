/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:19:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/06 15:12:38 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"
#include <stdlib.h>


void ft_cleanshell(t_minishell *node)
{
	t_minishell *current = node;
    t_minishell *next;

    while (current != NULL) {
        // Free memory for dynamically allocated arrays in the structure
        for (int i = 0; i < current->len_tab; i++) {
            free(current->cmd[i]);
            free(current->cmdt[i]);
            free(current->files[i]);
            free(current->afcmd_t[i]);
        }
        free(current->cmd);
        free(current->cmdt);
        free(current->files);
        free(current->afcmd_t);
        free(current->tab);

        next = current->next; // Save the next node
        free(current);        // Free the current node
        current = next;       // Move to the next node
    }
	node = NULL;
}
