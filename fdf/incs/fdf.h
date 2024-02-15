/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:50:30 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/15 14:30:48 by sben-rho         ###   ########.fr       */
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

typedef struct s_colors
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}			t_colors;

typedef struct s_img_vars
{
	void	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	float	z_scale_quotient;
	t_colors	color;
}			t_img_vars;


typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*start;
	t_img_vars	*img;
}				t_mlx;


int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(int button, int x, int y, t_mlx *mlx);
void	draw_pixel(char *buffer, int pixel, t_colors color, int endian);
void	pix_draw(t_img_vars *img, int x, int y);
void	drawto(t_img_vars *img, t_coord *co);
//char	**parsing(char *argv);
char	**parsing(int fd);
void 	fill_list(char **result, t_map **map);
t_map 	*calculate_coord(t_map *map);
void	free_char(char **result, int limit);
int		ft_linelen(t_map *li);
int		ft_listlen(t_map *li);
void	*ft_lst_clear(t_map *li);
void	ft_lstrm_back(t_map **li);
void	ft_lstadd_back(t_map **li, int x, char *color, int real);
char	*ft_strndup(const char *s, unsigned int n);
void	free_all(t_mlx *mlx, void *start, int i);
int		ft_close(t_mlx *mlx);
void	co_to_struct(t_coord *co, float x, float y, float x1, float y1);
void	draw_all(t_img_vars *img, t_map *map);
void	check_file(char *argv);
int		open_file(char *argv);




#endif