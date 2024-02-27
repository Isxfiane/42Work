/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:49 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/23 13:26:22 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	moove(t_mlx *mlx, float x, float y)
{
	t_map		*map;
	t_img_vars	newimg;

	map = mlx->start;
	while (map->next != NULL)
	{
		map->x += x;
		map->y += y;
		map = map->next;
	}
	map->x += x;
	map->y += y;
	map = mlx->start;
	init_img(&newimg, *mlx);
	draw_all(&newimg, map, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, newimg.img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	(*mlx->img) = newimg;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		free_all(mlx, mlx->start, 1);
		exit(0);
	}
	if (keycode == 119)
		moove(mlx, 10, 0);
	if (keycode == 97)
		moove(mlx, 0, 10);
	if (keycode == 115)
		moove(mlx, -10, 0);
	if (keycode == 100)
		moove(mlx, 0, -10);
	return (0);
}
