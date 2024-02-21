/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:44:57 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/20 11:35:22 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pix_draw(t_img_vars *img, int x, int y, t_colors col)
{
	int	pixel;

	if (x >= WIDTH || y >= HEIGHT || 0 >= x || 0 >= y)
		return ;
	pixel = (x * img->line_bytes) + (y * img->pixel_bits / 8);
	draw_pixel(img->buffer, pixel, col, img->endian);
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

int	set_delta(t_delta *d, t_coord *co, t_colors before, t_colors new)
{
	int		pixels;

	d->delta_x = co->x1 - co->x0;
	d->delta_y = co->y1 - co->y0;
	pixels = sqrt((d->delta_x * d->delta_x) + (d->delta_y * d->delta_y));
	d->delta_x = d->delta_x / pixels;
	d->delta_y = d->delta_y / pixels;
	d->delta_r = (float)(new.r - before.r) / pixels;
	d->delta_g = (float)(new.g - before.g) / pixels;
	d->delta_b = (float)(new.b - before.b) / pixels;
	return (pixels);
}

void	drawto(t_img_vars *img, t_coord *co, t_colors colnew, t_colors before)
{
	int		pixels;
	t_delta	delta;

	pixels = set_delta(&delta, co, before, colnew);
	while (pixels--)
	{
		pix_draw(img, co->x0, co->y0, before);
		co->z0++;
		co->x0 += delta.delta_x;
		co->y0 += delta.delta_y;
		before.r += delta.delta_r;
		before.g += delta.delta_g;
		before.b += delta.delta_b;
	}
}
