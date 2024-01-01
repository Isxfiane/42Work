/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:34:28 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/22 14:39:24 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TEST_H
# define TEST_H

# include "stdio.h" // La con de toi oublie le pas
# include "stdlib.h"
# include "libft.h"

typedef struct s_list{
	int				content;
	struct s_list	*next;
}	t_list;

//--------------------Function_Random-------------------------//
long int	ft_atol(const char *nptr);//						|
//------------------------------------------------------------//
//-------------------List_function------------------------------------------//
int			isemptylt(t_list *li); // (-1) VIDE || (0) REMPLIE              |
int			ft_listlen(t_list *li); // len de la liste                      |
int			ft_listchr(t_list *li, long int x); // Cherche et renvoie pos   |
void		ft_print_list(t_list *li); // Printf la con de toi              |
//--------------------------------------------------------------------------//
void		ft_lstadd_back(t_list **li, int x); // ADD-BACK
void		ft_lstadd_front(t_list **li, int x); // ADD-FRONT
void		ft_lstrm_back(t_list **li); // RM-BACK
void		ft_lstrm_front(t_list **li); // RM-FRONT
t_list		*ft_fill_numb(t_list *li, int argc, char **argv); // Remplie liste de nombre
void		*ft_lst_clear(t_list *li); // clear all
//--------------------------------------------------------------//

//----------------------Function_Game-----------------------//
void		ft_lst_swap(t_list *a, char *print); // sa | sb | ss			|
void		ft_lst_push(t_list **a, t_list **b,  char *print); // pa | pb	| /!\ Attention
void		ft_lst_rot(t_list **a, char *print); // ra | rb | rr			|	cas de segfault & leaks /!
void		ft_lst_rerot(t_list **a, char *print); // rra | rrb | rrr	|
//----------------------------------------------------------//

//----------------------Function_Algo-------------------------------//
void	ft_mainalgo(t_list **li, t_list **b); // Fontion directrice algo			|
int		ft_findmax(t_list *li); // Trouve le MAX et enovie valeur	|
int		ft_findmin(t_list *li); // Trouve le MIN et enovie valeur	|
int	    ft_isorder(t_list *li); // Liste en ordre ou pas			|
void	case_two(t_list *li, char *c);
void	case_three(t_list **li);
int		ft_isreverse(t_list *li);
void	ft_lst_reverse(t_list **li);
//-------------------------------------------------------------------//
#endif