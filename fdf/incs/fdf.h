/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:50:30 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/08 15:39:28 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>


# define HEIGHT 1920
# define WIDTH 1080


typedef struct s_map
{
	float			x;
	float			y;
	int				z;
	char 			*color;
	int 			real;
	struct s_map	*next;
}		t_map;

typedef struct s_coord
{
	float	x0;
	float	y0;
	int		z0;
	float	x1;
	float	y1;
}				t_coord;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img_vars
{
	void	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	float	z_scale_quotient;
}			t_img_vars;

typedef struct s_colors
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}			t_colors;

int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(int button, int x, int y, t_mlx *mlx);
void	draw_pixel(char *buffer, int pixel, t_colors color, int endian);
void	pix_draw(t_img_vars *img, t_colors *color, int x, int y);
void	drawto(t_img_vars *img, t_colors *col, t_coord *co);
char	**parsing(char *argv);
void 	fill_list(char **result, t_map **map);
t_map 	*calculate_coord(t_map *map);
void	free_char(char **result, int limit);

#endif