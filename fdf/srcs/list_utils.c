/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:24:57 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/09 13:26:39 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstadd_back(t_map **li, int x, char *color, int real)
{
	t_map	*element;
	t_map	*temp;

	element = malloc(sizeof(*element));
	if (!element)
		return ;
	element->z = x;
	element->color = color;
	element->real = real;
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

void	ft_lstrm_back(t_map **li)
{
	t_map	*temp;
	t_map	*beforetemp;

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
	free(temp->color);
	free(temp);
}

void	*ft_lst_clear(t_map *li)
{
	while (li != NULL)
		ft_lstrm_back(&li);
	return (NULL);
}

int	ft_listlen(t_map *li)
{
	int	size;

	size = 0;
	while (li != NULL)
	{
		size++;
		li = li->next;
	}
	return (size);
}
