/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:51:33 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/27 12:30:17 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	minialgo(t_list **la, t_list **lb)
{
	int	min;
	int	max;
	int	content;

	max = ft_findmax((*lb));
	min = ft_findmin((*lb));
	content = (*la)->content;
	if (content < min || content > max)
	{
		if (ft_isreverse((*lb)) == -1)
			ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
		if (ft_lst_push(la, lb, "pb") == -1)
		{
			ft_lst_clear(*la);
			ft_lst_clear(*lb);
			exit(1);
		}
	}
	else
		safeplace(la, lb, content);
}

void	repush(t_list **la, t_list **lb, int limit)
{
	int	j;

	j = -1;
	ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
	while (++j != limit)
		ft_lst_push(lb, la, "pa");
	j = -1;
	while (++j != limit)
		ft_lst_rot(la, "ra");
	j = -1;
}

void	pushandrepush(t_list **la, t_list **lb, int limit)
{
	int	len;
	int	i;

	len = ft_listlen(*la) + 1;
	i = 0;
	while (len != 0)
	{
		if (i == limit)
		{
			repush(la, lb, limit);
			i = 0;
		}
		minialgo(la, lb);
		len--;
		i++;
	}
}

void	sortbigaglo(t_list **la, t_list **lb, int len)
{
	float	test;

	test = (3.0 / 40.0) * len + 12.5;
	ft_lst_rerot(la, "rra");
	pushandrepush(la, lb, test);
	logicalpush(la, lb, test);
	ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
	logcical_replace(la, lb);
}
