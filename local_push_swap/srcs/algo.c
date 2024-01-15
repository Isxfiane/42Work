/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:20:17 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/15 13:46:23 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	safeplace(t_list **la, t_list **lb, int content)
{
	int	near;

	near = ft_lst_find_near((*lb), content);
	ft_lst_reverse(lb, near, "rb", "rrb");
	if (near > content)
		ft_lst_rot(lb, "rb");
	ft_lst_push(la, lb, "pb");
}

void	logicalpush(t_list **la, t_list **lb, int limit)
{
	int	min;
	int	max;
	int	content;

	ft_lst_push(la, lb, "pb");
	ft_lst_push(la, lb, "pb");
	if (ft_isorder(*lb) == 0)
		ft_lst_swap(*lb, "sb");
	while (ft_listlen((*la)) > limit)
	{
		max = ft_findmax((*lb));
		min = ft_findmin((*lb));
		content = (*la)->content;
		if (content < min || content > max)
		{
			if (ft_isreverse((*lb)) == -1)
				ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
			ft_lst_push(la, lb, "pb");
//			if (content > max)
//				ft_lst_rot(lb, "rb"); PLUS QUE 1
		}
		else
			safeplace(la, lb, content);
	}
}

void	rotpush(t_list **la, t_list **lb, int x)
{
	int	temp;

	temp = ft_lst_find_near(*la, x);
	ft_lst_reverse(la, temp, "ra", "rra");
	if (temp < x)
		ft_lst_rot(la, "ra");
	ft_lst_push(lb, la, "pa");
}

void	logcical_replace(t_list **la, t_list **lb)
{
	int	temp;

	while (ft_listlen(*lb) != 0)
	{
		temp = (*lb)->content;
		if (temp > ft_findmax(*la)
			|| temp < ft_findmin(*la))
		{
			if (ft_isorder(*la) == -1)
				ft_lst_reverse(la, ft_findmin(*la), "ra", "rra");
			ft_lst_push(lb, la, "pa");
		}
		else
			rotpush(la, lb, temp);
	}
	ft_lst_reverse(la, ft_findmin(*la), "ra", "rra");
}

void	ft_mainalgo(t_list **li, t_list **b)
{
	int	len;

	len = ft_listlen(*li);
	if (ft_isorder(*li) == 0)
		return ;
	if (len == 0 || len == 1)
		return ;
	if (len == 2)
		case_two(*li, "sa");
	if (len == 3)
		case_three(li);
	if (len == 4)
		case_for(li, b);
	if (len > 4  && len < 45)
	{
		logicalpush(li, b, 3);
		ft_lst_reverse(b, ft_findmax((*b)), "rb", "rrb");
		case_three(li);
		logcical_replace(li, b);
	}
	if (len > 45)
		sortbigaglo(li, b, len);
}
