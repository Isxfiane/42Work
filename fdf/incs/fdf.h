#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>


typedef struct s_coord{
	float	x0;
	float	y0;
	int	z0;
	float	x1;
	float	y1;
}				t_coord;

typedef struct	s_mlx {
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


int	key_hook(int keycode, t_mlx *mlx);
int mouse_hook(int button, int x,int y, t_mlx *mlx);
void	draw_pixel(char *buffer, int pixel, t_colors color, int endian);
void	pix_draw(t_img_vars *img,t_colors *color, int x, int y);
void	drawto(t_img_vars *img, t_colors *col, t_coord *co);



/*
 * 	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	float	z_scale_quotient;
 */

#endif