/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:24:42 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/10 10:59:30 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	case_two(t_list *li, char *str)
{
	if (ft_isorder(li) == -1)
	{
		ft_lst_swap(li, str);
	}
}

t_list	*algoforthree(t_list **li, int min, int max)
{
	if (min == 2 && max == 3)
		case_two(*li, "sa");
	else if (max == 1 && min == 3)
	{
		case_two(*li, "sa");
		ft_lst_rerot(li, "rra");
	}
	else if (max == 1 && min == 2)
		ft_lst_rot(li, "ra");
	else if (min == 1 && max == 2)
	{
		case_two(*li, "sa");
		ft_lst_rot(li, "ra");
	}
	else if (max == 2 && min == 3)
		ft_lst_rerot(li, "rra");
	return (*li);
}

void	case_three(t_list **li)
{
	int	min;
	int	max;
	int	inmin;
	int	inmax;

	if (ft_isorder(*li) == 0)
		return ;
	max = ft_findmax(*li);
	min = ft_findmin(*li);
	inmin = ft_listchr(*li, min);
	inmax = ft_listchr(*li, max);
	algoforthree(li, inmin, inmax);
}

void	case_for(t_list **la, t_list **lb)
{
	int	inmin;
	int	inmax;

	ft_lst_push(la, lb, "pb");
	inmin = ft_listchr(*la, ft_findmin(*la));
	inmax = ft_listchr(*la, ft_findmax(*la));
	algoforthree(la, inmin, inmax);
	rotpush(la, lb, (*lb)->content);
	ft_lst_reverse(la, ft_findmin(*la), "ra", "rra");
}
