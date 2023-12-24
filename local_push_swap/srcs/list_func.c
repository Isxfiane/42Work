/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:23:28 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/22 14:36:08 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	ft_listchr(t_list *li, long int x)
{
	int i;

	if (isemptylt(li) == -1)
		return (0);
	i = 1;
	while (li != NULL)
	{
		if (li->content == x)
			return (i);
		i++;
		li = li->next;
	}
	return (0);
}

t_list	*ft_lstrm_back(t_list *li)
{
	t_list	*temp;
	t_list	*beforetemp;

	if (isemptylt(li) == -1)
		return (NULL);
	if (li->next == NULL)
	{
		free(li);
		return (NULL);
	}
	temp = li;
	beforetemp = li;
	while (temp->next != NULL)
	{
		beforetemp = temp;
		temp = temp->next;
	}
	beforetemp->next = NULL;
	free(temp);
	return (li);
}

t_list	*ft_lstrm_front(t_list *li)
{
	t_list	*element;

	if (isemptylt(li) == -1)
		return (NULL);
	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element = li->next;
	free(li);
	return (element);
}

t_list	*ft_lst_clear(t_list *li)
{
	if (isemptylt(li) == -1)
		return (NULL);
	while (li != NULL)
		li = ft_lstrm_back(li);
	return (NULL);
}
