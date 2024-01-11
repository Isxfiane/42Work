/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:28 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/11 13:46:58 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TEST_H
# define TEST_H

# include "stdio.h" //a con de toi oublie le pas
# include <stdlib.h>
# include "libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

long int	ft_atol(const char *nptr);

int			isemptylt(t_list *li);
int			ft_listlen(t_list *li);
int			ft_listchr(t_list *li, long int x);
void		ft_print_list(t_list *li); //A tej

void		ft_lstadd_back(t_list **li, int x);
void		ft_lstadd_front(t_list **li, int x);
void		ft_lstrm_back(t_list **li);
void		ft_lstrm_front(t_list **li);

t_list		*ft_fill_numb(t_list *li, int argc, char **argv);
void		*ft_lst_clear(t_list *li);

void		ft_lst_swap(t_list *a, char *print);
void		ft_lst_push(t_list **a, t_list **b, char *print);
void		ft_lst_rot(t_list **a, char *print);
void		ft_lst_rerot(t_list **a, char *print);

void		ft_mainalgo(t_list **li, t_list **b);
int			ft_findmax(t_list *li);
int			ft_findmin(t_list *li);
int			ft_isorder(t_list *li);
void		case_two(t_list *li, char *c);
void		case_three(t_list **li);
void		case_for(t_list **la, t_list **lb);
int			ft_isreverse(t_list *li);
void		ft_lst_reverse(t_list **li, int x, char *rot, char *rerot);
int			ft_lst_find_near(t_list *li, int nb);
void		logcical_replace(t_list **la, t_list **lb);
void		rotpush(t_list **la, t_list **lb, int x);
#endif