/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:25:13 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/22 15:25:46 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_last_coord(t_map *map, t_map *before, int sep_w)
{
	if (map->x == before->x)
		map->y = before->y + sep_w;
	else
		map->y = 50;
}

void	find_coord(t_map *map, t_map *before, int sep_h, int sep_w)
{
	int	n;

	n = 0;
	while (map->next != NULL)
	{
		if (map->real == -1)
		{
			n++;
			map = map->next;
			if (map->next == NULL)
				break ;
		}
		map->x = 50 + sep_h * n;
		map->z = map->z * 5;
		if (map->x == before->x)
			map->y = before->y + sep_w;
		else
			map->y = 50;
		before = map;
		map = map->next;
	}
	map->x = 50 + sep_h * n;
	map->z = map->z * 5;
	set_last_coord(map, before, sep_w);
}

t_map	*calculate_coord(t_map *map)
{
	int		len;
	float	sep_h;
	float	sep_w;
	t_map	*before;

	len = ft_linelen(map);
	sep_w = (WIDTH - 100) / (ft_listlen(map) / len);
	sep_h = (HEIGHT - 100) / len;
	map->x = 50;
	map->y = 50;
	map->z = map->z * 5;
	before = map;
	map = map->next;
	find_coord(map, before, sep_w, sep_h);
	return (map);
}
