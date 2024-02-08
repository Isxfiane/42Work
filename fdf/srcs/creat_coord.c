/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:25:13 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/08 15:41:55 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_map 	*calculate_coord(t_map *map)
{
	int		len;
	float	sep_h;
	float	sep_w;
	t_map	*before;
	int		n;

	before = map;
	len = ft_listlen(map);
	sep_h = (HEIGHT - 100) / len;
	sep_w = (WIDTH - 100) / len;
	n = 0;
	map->x = 50;
	map->y = 50;
	before = map;
	map = map->next;
	while (map->next != NULL)
	{
		if (map->real == -1)
		{
			n++;
			map = map->next;
			if (map->next == NULL)
				break;
		}
		map->x = 50 + sep_h * n;
		if (map->x == before->x)
			map->y = before->y + sep_h;
		else
			map->y = 50;
		before = map;
		map = map->next;
	}
	map->x = 50 + sep_h * n;
	if (map->x == before->x)
		map->y = before->y + sep_h;
	else
		map->y = 50;
	return (map);
}