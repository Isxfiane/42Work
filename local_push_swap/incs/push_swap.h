/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:28 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/27 13:00:09 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int			ft_lstadd_back(t_list **li, int x);
int			ft_lstadd_front(t_list **li, int x);
void		ft_lstrm_back(t_list **li);
void		ft_lstrm_front(t_list **li);
void		*ft_lst_clear(t_list *li);

void		ft_lst_swap(t_list *a, char *print);
int			ft_lst_push(t_list **a, t_list **b, char *print);
int			ft_lst_rot(t_list **a, char *print);
int			ft_lst_rerot(t_list **a, char *print);

int			ft_findmax(t_list *li);
int			ft_findmin(t_list *li);
int			ft_findnear(t_list *li, int nb);
int			ft_isorder(t_list *li);
int			ft_isreverse(t_list *li);

void		ft_lst_reverse(t_list **li, int x, char *rot, char *rerot);
void		logcical_replace(t_list **la, t_list **lb);
void		rotpush(t_list **la, t_list **lb, int x);

void		case_two(t_list *li, char *c);
void		case_three(t_list **li);
void		case_for(t_list **la, t_list **lb);

t_list		*ft_fill_numb(t_list *li, int argc, char **argv);
void		ft_mainalgo(t_list **li, t_list **b);
void		sortbigaglo(t_list **la, t_list **lb, int len);
void		safeplace(t_list **la, t_list **lb, int content);
void		pushandrepush(t_list **la, t_list **lb, int limit);
void		logicalpush(t_list **la, t_list **lb, int limit);
#endif