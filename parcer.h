/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:32:52 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/14 11:44:03 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "libft/libft.h"

t_node	*parcing(char *str);
char	**ft_splitt(char *str);
int	number_of_word(char *str);
int	ft_vtk(char c);
int  *ft_arr_tk(char *str, int len);
int ft_set_tk(char *str);
char	**ft_spliter(char *s);
int   ft_parq(char *str, int *i,char f);
void hudler_o(char *s1,int i,int *op,size_t *len_word);
char  *hudler_t(char *s1,char *word, int *id);
void	ft_skep (char *str, int *i);
