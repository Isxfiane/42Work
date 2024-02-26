/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:24:57 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/26 17:18:01 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_lstadd_front(t_map **li, int x, char *color, int real)
{
	t_map	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (-1);
	element->z = x;
	element->color = color;
	element->real = real;
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
	return (0);
}

void	ft_lst_reverse(t_map **map)
{
	t_map	*prev;
	t_map	*current;
	t_map	*next;

	current = *map;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*map = prev;
}

void	ft_lstrm_front(t_map **li)
{
	t_map	*tmp;

	if (*li == NULL)
		return ;
	tmp = *li;
	*li = (*li)->next;
	free(tmp->color);
	free(tmp);
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
