/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:27:10 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/22 14:01:16 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//---------------------------------FICHIER ALGO-------------------------------//
#include "test.h"

/*
 * Fonction directrice :
 * 				Identification du chiffre a traitrer | recup du min / max |determination de la marge a suivre
 * 		fonction secondaire :
 * 					- rb | rrb de la pile B jusqu'a liste en ordre (nb en dehors du Min/Max)
 * 					- Met en haut le chiffre le plus proche du nb
 * 						- push et swap si besoin
 *
 *
 * 		check note.txt au besoin
 */

int	ft_findmax(t_list *li)
{
	t_list *stack;
	int	max;

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

int ft_findmin(t_list *li)
{
	t_list *stack;
	int	min;

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

int	ft_isorder(t_list *li)
{
	t_list	*temp;
	int		p1;
	int		p2;

	temp = li;
	p2 = 0;
	while(temp->next != NULL)
	{
		p1 = temp->content;
		if (p1 < p2 && p2 != 0)
			return (-1);
		p2 = p1;
		temp=temp->next;
	}
	if (temp->content < p2)
		return (-1);
	return (0);
}
// remise en place de la liste

int	ft_isreverse(t_list *li)
{
	t_list	*temp;
	int		p1;
	int		p2;

	temp = li;
	p2 = 0;
	while(temp->next != NULL)
	{
		p1 = temp->content;
		if (p1 > p2 && p2 != 0)
			return (-1);
		p2 = p1;
		temp=temp->next;
	}
	if (temp->content > p2)
		return (-1);
	return (0);
}

void	ft_lst_reverse(t_list **li)
{
	int	index;
	int len;
	int nb;

	len = ft_listlen((*li)) + 1;
	index = ft_listchr((*li), ft_findmax((*li)));
	index = index - 1;
	ft_printf("NB = %d | len = %d | index = %d\n", nb, len , index);
	if (len / 2 < index + 1)
	{
		while (++index < len)
			ft_lst_rerot(li, "rrb");
	}
	else
	{
		while (index != 0)
		{
			ft_lst_rot(li, "rb");
			index--;
		}
	}
}