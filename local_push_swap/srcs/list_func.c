/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_base_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:23:21 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/05 09:37:27 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"
/*
int		isemptylt(t_list *li);
int		ft_listlen(t_list *li);
void	ft_print_list(t_list *li);
int		ft_isorder(t_list *li);
int		ft_isreverse(t_list *li);
*/

int	isemptylt(t_list *li)
{
	if (li == NULL)
		return (-1);
	return (0);
}

int	ft_listlen(t_list *li)
{
	int	size;

	size = 0;
	if (isemptylt(li) == -1)
		return (size);
	while (li != NULL)
	{
		size++;
		li = li->next;
	}
	return (size);
}

void	ft_print_list(t_list *li)
{
	if (isemptylt(li) == -1)
		return ;
	while (li != NULL)
	{
		ft_printf("[%d]", li->content);
		li = li->next;
	}
	ft_printf("\n");
}

int	ft_isorder(t_list *li)
{
	t_list	*temp;
	int		p1;
	int		p2;

	temp = li;
	p2 = 0;
	if (isemptylt(li) == -1)
		return (0);
	while (temp->next != NULL)
	{
		p1 = temp->content;
		if (p1 < p2 && p2 != 0)
			return (-1);
		p2 = p1;
		temp = temp->next;
	}
	if (temp->content < p2)
		return (-1);
	return (0);
}

int	ft_isreverse(t_list *li)
{
	t_list		*temp;
	int			p1;
	long int	p2;

	temp = li;
	p2 = -21474836475;
	if (li == NULL)
		return (0);
	while (temp->next != NULL)
	{
		p1 = temp->content;
		if (p1 > p2 && p2 != 0)
			return (-1);
		p2 = p1;
		temp = temp->next;
	}
	if (temp->content > p2)
		return (-1);
	return (0);
}
