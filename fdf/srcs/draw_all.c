/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:26 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/20 14:11:59 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_to_map(t_map *before, t_map *lbefore, t_img_vars *img)
{
	t_coord		co;
	t_colors	cbefore;
	t_colors	clbefore;


	co.x0 = before->x;
	co.x1 = lbefore->x;
	co.y1 = lbefore->y;
	co.y0 = before->y;
	clbefore = hex_to_rgb(lbefore->color);
	cbefore = hex_to_rgb(before->color);
	drawto(img, &co, clbefore, cbefore);
}

void	draw_full(t_map *map, t_map *before, t_map *lbefore, t_img_vars *img)
{
	while (map->next != NULL)
	{
		map = map->next;
		before = map;
		map = map->next;
		while (map->real != -1 && map->next != NULL)
		{
			draw_to_map(before, lbefore, img);
			draw_to_map(before, map, img);
			before = map;
			map = map->next;
			lbefore = lbefore->next;
			if (lbefore->real == -1)
				lbefore = lbefore->next;
		}
		draw_to_map(before, lbefore, img);
		lbefore = lbefore->next;
		if (lbefore->real == -1)
			lbefore = lbefore->next;
	}
	draw_to_map(before, map, img);
	draw_to_map(map, lbefore, img);
}

void	draw_all(t_img_vars *img, t_map *map)
{
	t_map		*before;
	t_map		*lbefore;

	before = map;
	map = map->next;
	lbefore = before;
	while (map->real != -1 && map->next != NULL)
	{
		draw_to_map(before, map, img);
		before = map;
		map = map->next;
	}
	draw_full(map, before, lbefore, img);
}
