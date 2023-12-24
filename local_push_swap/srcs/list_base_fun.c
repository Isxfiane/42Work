/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_base_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:23:21 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/19 18:37:36 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"
// ft_lstnew -> new list avec le bloc bloc de set
// ft_lstadd_front --> puhs_front_list
// ft_lstadd_back --> push_back_list

int	isemptylt(t_list *li)
{
	if (li == NULL)
		return (-1);
	return (0);
}

int	ft_listlen(t_list *li) // ft_lstsize
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

void	ft_print_list(t_list *li) // A voir si retrait ou pas
{
	if (isemptylt(li) == -1)
		return;
	while (li != NULL)
	{
		ft_printf("[%d]", li->content); // Printf la con de toi
		li = li->next;
	}
	ft_printf("\n"); // Printf la con de toi
}

t_list	*ft_lstadd_back(t_list *li, int x)
{
	t_list	*element;
	t_list	*temp;
	t_list	*beforetemp;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = x;
	element->next = NULL;
	if (isemptylt(li) == -1)
		return (element);
	temp = li;
	while (temp->next != NULL)
	{
		beforetemp = temp;
		temp = temp->next;
	}
	temp->next = element;
	return (li);
}

t_list	*ft_lstadd_front(t_list *li, int x)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = x;
	if (isemptylt(li) == -1)
	{
		element->next = NULL;
		return (element);
	}
	else
	{
		element->next = li;
		return (element);
	}
}
