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
	if (*li == NULL)
		return;
	t_list *tmp = *li;
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
