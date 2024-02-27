/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chr_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:27:10 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/16 11:06:10 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findmax(t_list *li)
{
	t_list	*stack;
	int		max;

	if (isemptylt(li) == -1)
		return (-1);
	stack = li;
	max = stack->content;
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->content > max)
			max = stack->content;
	}
	return (max);
}

int	ft_findmin(t_list *li)
{
	t_list	*stack;
	int		min;

	if (isemptylt(li) == -1)
		return (-1);
	stack = li;
	min = stack->content;
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->content < min)
			min = stack->content;
	}
	return (min);
}

int	calc(int a, int b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

int	ft_findnear(t_list *li, int nb)
{
	int	betterresult;
	int	betternb;
	int	len;
	int	i;
	int	temp;

	betternb = nb;
	betterresult = 2147483647;
	len = ft_listlen(li);
	i = 0;
	while (i != len)
	{
		temp = calc(li->content, nb);
		if (temp <= betterresult)
		{
			if (betternb < li->content || betternb == nb
				|| temp != betterresult)
				betternb = li->content;
			betterresult = temp;
		}
		li = li->next;
		i++;
	}
	return (betternb);
}
