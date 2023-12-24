/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:06:08 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/21 16:53:59 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	ft_lst_swap(t_list *a)
{
	t_list *before;
	int	temp;

	if (isemptylt(a) == -1 || ft_listlen(a) <= 1)
		return ;
	before = a;
	before= before->next;
	temp = a->content;
	a->content = before->content;
	a = a->next;
	a->content = temp;
}

void	ft_lst_push(t_list *a, t_list * b)
{
	int tempa;

	if (isemptylt(b) == -1)
		return ;
	tempa = a->content;
	a->content = b->content;
	b->content = tempa;
}

t_list	*ft_lst_rot(t_list *a)
{
	int temp;

	if (ft_listlen(a) <= 1)
		return (a);
	temp = a->content;
	a = ft_lstrm_front(a);
	ft_lstadd_back(a, temp);
	return (a);
}

t_list	*ft_lst_rerot(t_list *a)
{
	t_list *acp;
	int temp;

	if (ft_listlen(a) >= 1)
		return (a);
	acp = a;
	while (acp->next != NULL)
		acp = acp->next;
	temp = acp->content;
	a = ft_lstrm_back(a);
	a = ft_lstadd_front(a, temp);
	return (a);
}