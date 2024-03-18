/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:32:52 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/18 17:25:40 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "libft/libft.h"


t_docker	*parcing(char *str);
void	ft_get_len(char *s1,int i, size_t *len_word);
char	**ft_splitt(char *str);
void	hun_par(char *s1, int *id, int *i, char *word);
int	number_of_word(char *str);
void	is_quot_(char *str,int *i);
void	hund(char *s1, int *id, int *i, char *word);
int	ft_vtk(char c);
int  *ft_arr_tk(char *str, int len);
int ft_set_tk(char *str);
char	**ft_spliter(char *s);
int   ft_parq(char *str, int *i,char f);
void hudler_o(char *s1,int i,int *op,size_t *len_word);
char  *hudler_t(char *s1,char *word, int *id);
void	ft_skep (char *str, int *i);
char	**handle_of_malloc(char **tab);
int	get_des(char c);
t_docker	*get_link_cmd(char **str,int *b_arr);
char	**ft_splits(char *s);
