/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:26 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/10 14:57:19 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_top(t_img_vars *img, t_map *map, float save_h, t_coord co, t_colors color)
{
	co_to_struct(&co, map->x, map->y, save_h, map->y);
	drawto(img, &color, &co);
}


void	draw_all(t_img_vars *img, t_map *map, t_colors color, t_mlx mlx)
{
	t_map		*before;
	t_coord		co;
	float 		save_h;

	before = map;
	map = map->next;
	save_h = map->x;
	while (map->real != -1)
	{
		co_to_struct(&co, before->x, before->y, map->x, map->y);
		drawto(img, &color, &co);
		before = map;
		map = map->next;
	}
	while (map->next != NULL)
	{
		map = map->next;
		before = map;
		map = map->next;
		while (map->real != -1 && map->next != NULL)
		{
			draw_top(img, before, save_h, co, color);
			co_to_struct(&co, before->x, before->y, map->x, map->y);
			drawto(img, &color, &co);
			before = map;
			map = map->next;
		}
	}
		draw_top(img, before, save_h, co, color);
	if (map->real == -1)
		return ;
		co_to_struct(&co, before->x, before->y, map->x, map->y);
		drawto(img, &color, &co);
		draw_top(img, map, save_h, co, color);
}
