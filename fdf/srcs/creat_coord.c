/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:25:13 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/07 15:57:29 by sben-rho         ###   ########.fr       */
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
	int len;
	float sep_h;
	float sep_w;
	t_map *before;

	before = map;
	len = ft_listlen(map);
	sep_h = (HEIGHT - 100) / len;
	sep_w = (WIDTH - 100) / len;
	map->x = 50;
	map->y = 50;
	map = map->next;
	while (map->next != NULL)
	{
		map->x = before->x + sep_h;
		map->y = before->y + sep_w;
		before = map;
		map = map->next;
	}
	map->x = before->x + sep_h;
	map->y = before->y + sep_w;
	return (map);
}