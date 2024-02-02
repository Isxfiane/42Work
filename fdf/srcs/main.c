/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:25:19 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/02 16:47:00 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	main(void)
{
	t_mlx		mlx;
	t_img_vars	img;
	t_coord		coord;
	int			pixel;
	t_colors	color;


	color.a = 1;
	color.r = 164;
	color.g = 255;
	color.b = 164;
	//-------------Start-----------//
	coord.z0 = 6;
	coord.x0 = 50;
	coord.y0 = 200;

	coord.x0 = (1 / sqrtf(2)) * coord.x0 + (1 / sqrt(2)) * coord.y0;
	coord.y0 = -(1 / sqrtf(6)) * coord.x0 + (1 / sqrt(6)) * coord.y0 - (2 / sqrt(6)) * coord.z0;
	//-----------Go to------------//
	coord.x1 = 500;
	coord.y1 = 200;
	coord.z0 = 0;
	coord.x1 = (1 / sqrtf(2)) * coord.x1 + (1 / sqrt(2)) * coord.y1;
	coord.y1 = -(1 / sqrtf(6)) * coord.x1 + (1 / sqrt(6)) * coord.y1 - (2 / sqrt(6)) * coord.z0;
//---------------------Init--------------------------//
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
//---------------------Hook--------------------------//
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
//---------------------IMG--------------------------//
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.buffer = mlx_get_data_addr(img.img, &img.pixel_bits, &img.line_bytes, &img.endian);
	drawto(&img, &color, &coord);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
//---------------------Loop-------------------------//
	mlx_loop(mlx.mlx);
//---------------------Free-------------------------//
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	return (0);
}