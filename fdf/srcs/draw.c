/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:44:57 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/12 12:08:10 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pix_draw(t_img_vars *img, t_colors *color, int x, int y)
{
	int	pixel;

	if (x > WIDTH || y > HEIGHT || 0 > x || 0 > y)
		return ;
	pixel = (x * img->line_bytes) + (y * img->pixel_bits / 8);
	draw_pixel(img->buffer, pixel, *color, img->endian);
}

void	draw_pixel(char *buffer, int pixel, t_colors color, int endian)
{
	if (endian == 1)
	{
		buffer[pixel + 0] = color.a;
		buffer[pixel + 1] = color.r;
		buffer[pixel + 2] = color.g;
		buffer[pixel + 3] = color.b;
	}
	else if (endian == 0)
	{
		buffer[pixel + 0] = color.b;
		buffer[pixel + 1] = color.g;
		buffer[pixel + 2] = color.r;
		buffer[pixel + 3] = color.a;
	}
}


void	co_to_struct(t_coord *co, float x, float y, float x1, float y1)
{
	co->x0 = x;
	co->x1 = x1;
	co->y1 = y1;
	co->y0 = y;
}

void	drawto(t_img_vars *img, t_colors *col, t_coord *co)
{
	float	delta_x;
	float	delta_y;
	int		pixels;

	delta_x = co->x1 - co->x0;
	delta_y = co->y1 - co->y0;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
	while (pixels--)
	{
		pix_draw(img, col, co->x0, co->y0);
		co->z0++;
		co->x0 += delta_x;
		co->y0 += delta_y;
	}
}
