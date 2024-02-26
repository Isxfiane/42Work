/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:52:26 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/26 17:00:52 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_to_map(t_map *before, t_map *lbefore, t_mlx *mlx)
{
	t_coord		co;
	t_colors	*cbefore;
	t_colors	*clbefore;

	co.x0 = before->x;
	co.x1 = lbefore->x;
	co.y1 = lbefore->y;
	co.y0 = before->y;
	clbefore = hex_to_rgb(lbefore->color);
	if (!clbefore)
	{
		free_all(mlx, mlx->start, 1);
		exit(1);
	}
	cbefore = hex_to_rgb(before->color);
	if (!cbefore)
	{
		free_all(mlx, mlx->start, 1);
		exit(1);
	}
	drawto(mlx->img, &co, *clbefore, *cbefore);
	free(clbefore);
	free(cbefore);
}

void	draw_line_one(t_map *before, t_map *lbefore, t_mlx *mlx)
{
	while (before != NULL)
	{
		draw_to_map(before, lbefore, mlx);
		lbefore = before;
		before = before->next;
		if (before == NULL)
			break ;
		else
			before = before->next;
	}
}

void	draw_last_side(t_map *map, t_map *before, t_map *lbefore, t_mlx *mlx)
{
	if (map->real != -1)
		draw_to_map(map, lbefore, mlx);
	if (map->real != -1)
		draw_to_map(before, map, mlx);
}

void	draw_full(t_map *map, t_map *before, t_map *lbefore, t_mlx *mlx)
{
	if (ft_linelen(map->next) == 1)
	{
		draw_line_one(before, lbefore, mlx);
		return ;
	}
	while (map->next != NULL)
	{
		map = map->next;
		before = map;
		map = map->next;
		while (map->real != -1 && map->next != NULL)
		{
			draw_to_map(before, lbefore, mlx);
			draw_to_map(before, map, mlx);
			before = map;
			map = map->next;
			lbefore = lbefore->next;
		}
		draw_to_map(before, lbefore, mlx);
		lbefore = lbefore->next;
		if (lbefore->real == -1)
			lbefore = lbefore->next;
	}
	draw_last_side(map, before, lbefore, mlx);
}

void	draw_all(t_img_vars *img, t_map *map, t_mlx *mlx)
{
	t_map		*before;
	t_map		*lbefore;
	t_mlx		cpy_mlx;

	cpy_mlx.mlx = mlx->mlx;
	cpy_mlx.win = mlx->win;
	cpy_mlx.start = mlx->start;
	cpy_mlx.img = img;
	before = map;
	map = map->next;
	lbefore = before;
	while (map->real != -1 && map->next != NULL)
	{
		draw_to_map(before, map, &cpy_mlx);
		before = map;
		map = map->next;
	}
	draw_full(map, before, lbefore, &cpy_mlx);
}
