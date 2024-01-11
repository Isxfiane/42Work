/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:23:28 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/05 09:31:46 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"
/*
void	ft_lstadd_back(t_list **li, int x);
void	ft_lstadd_front(t_list **li, int x);
void	ft_lstrm_back(t_list **li);
void	ft_lstrm_front(t_list **li);
void	*ft_lst_clear(t_list *li);
*/

void	ft_lstadd_back(t_list **li, int x)
{
	t_list	*element;
	t_list	*temp;

	element = malloc(sizeof(*element));
	if (!element)
		return ;
	element->content = x;
	element->next = NULL;
	if (*li == NULL)
	{
		*li = element;
		return ;
	}
	temp = *li;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = element;
}

void	ft_lstadd_front(t_list **li, int x)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return ;
	element->content = x;
	if (*li == NULL)
	{
		element->next = NULL;
		*li = element;
	}
	else
	{
		element->next = *li;
		*li = element;
	}
}

void	ft_lstrm_back(t_list **li)
{
	t_list	*temp;
	t_list	*beforetemp;

	if (*li == NULL)
		return ;
	if ((*li)->next == NULL)
	{
		free(*li);
		*li = NULL;
		return ;
	}
	temp = *li;
	beforetemp = *li;
	while (temp->next != NULL)
	{
		beforetemp = temp;
		temp = temp->next;
	}
	beforetemp->next = NULL;
	free(temp);
}

void	ft_lstrm_front(t_list **li)
{
	t_list	*tmp;

	if (*li == NULL)
		return ;
	tmp = *li;
	*li = (*li)->next;
	free(tmp);
}

void	*ft_lst_clear(t_list *li)
{
	if (isemptylt(li) == -1)
		return (NULL);
	while (li != NULL)
		ft_lstrm_back(&li);
	return (NULL);
}
