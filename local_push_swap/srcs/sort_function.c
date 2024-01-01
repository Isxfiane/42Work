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

void	ft_lst_swap(t_list *a, char *print)
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
	ft_printf("%s\n", print);
}

void	ft_lst_push(t_list **a, t_list **b,  char *print)
{
	int tempa;

	if (isemptylt(*a) == -1)
		return ;
	tempa = (*a)->content;
	ft_lstrm_front(a);
	ft_lstadd_front(b, tempa);
	ft_printf("%s\n", print);
}

void	ft_lst_rot(t_list **a, char *print)
{
	int temp;

	if (ft_listlen(*a) <= 1)
		return ;
	temp = (*a)->content;
	ft_lstrm_front(a);
	ft_lstadd_back(a, temp);
	ft_printf("%s\n", print);
}

void	ft_lst_rerot(t_list **a, char *print)
{
	t_list *acp;
	int temp;

	if (ft_listlen(*a) <= 1)
		return ;
	acp = *a;
	while (acp->next != NULL)
		acp = acp->next;
	temp = acp->content;
	ft_lstrm_back(a);
	ft_lstadd_front(a, temp);
	ft_printf("%s\n", print);
}