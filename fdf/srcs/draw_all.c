/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:26 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/14 12:00:41 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all(t_img_vars *img, t_map *map, t_colors color, t_mlx mlx)
{
	t_map		*before;
	t_coord		co;
	t_map		*linebefore;

	before = map;
	map = map->next;
	linebefore = mlx.start;
	while (map->real != -1 && map != NULL)
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
			co_to_struct(&co, before->x, before->y, linebefore->x, linebefore->y);
			drawto(img, &color, &co);
			co_to_struct(&co, before->x, before->y, map->x, map->y);
			drawto(img, &color, &co);
			before = map;
			map = map->next;
			linebefore = linebefore->next;
			if (linebefore->real == -1)
				linebefore = linebefore->next;
		}
		co_to_struct(&co, before->x, before->y, linebefore->x, linebefore->y);
		drawto(img, &color, &co);
		linebefore = linebefore->next;
		if (linebefore->real == -1)
			linebefore = linebefore->next;
	}
	co_to_struct(&co, before->x, before->y, map->x, map->y);
	drawto(img, &color, &co);
	before = before->next;
	co_to_struct(&co, map->x, map->y, linebefore->x, linebefore->y);
	drawto(img, &color, &co);
}
