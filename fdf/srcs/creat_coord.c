/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:25:13 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/12 16:34:50 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		map->z = map->z * 10;
		if (map->x == before->x)
			map->y = before->y + sep_w;
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
}

t_map	*calculate_coord(t_map *map)
{
	int		len;
	float	sep_h;
	float	sep_w;
	t_map	*before;
	int		n;

	before = map;
	len = ft_linelen(map);
	sep_w = (WIDTH - 100) / (ft_listlen(map) / len);
	sep_h = (HEIGHT - 100) / len;
	n = 0;
	map->x = 50;
	map->y = 50;
	before = map;
	map = map->next;
	find_coord(map, before, sep_w, sep_h);
	return (map);
}
