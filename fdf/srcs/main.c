/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:25:19 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/22 17:49:02 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*parsing_and_coord(char **argv)
{
	char	**result;
	t_map	*map;
	int		fd;

	map = NULL;
	check_file(argv[1]);
	fd = open_file(argv[1]);
	result = parsing(fd);
	if (!result)
		return (NULL);
	while (result != NULL)
	{
		fill_list(result, &map);
		free_char(result, 0);
		result = parsing(fd);
	}
	if (ft_listlen(map) == 1)
	{
		close(fd);
		ft_lst_clear(map);
		return (NULL);
	}
	ft_lst_reverse(&map);
	calculate_coord(map);
	close(fd);
	return (map);
}

void	init_and_hook(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fdf");
	mlx_hook(mlx->win, 02, 1L<<0, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, ft_close, mlx);
}

void	init_img(t_img_vars *img, t_mlx mlx)
{
	img->img = mlx_new_image(mlx.mlx, HEIGHT, WIDTH);
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
}

void	set_iso(t_map *map)
{
	while (map->next != NULL)
	{
		/*
		map->x *= 0.82 * (map->x - map->z) / sqrt(2);
		map->y *= 0.82 * (map->x + 2 * map->y + map->z) / sqrt(6);
		 */
		map->x = (float)-map->z + (map->y + map->x) * (float)sin(0.523599); // X doit negatif
		map->y = (map->x + map->y) * (float)cos(0.856);
		map = map->next;
	}
	map->x = (float)-map->z + (map->y + map->x) * (float)sin(0.523599);
	map->y = (map->x + map->y) * (float)cos(0.856);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		mlx;
	t_img_vars	img;

	(void)argc;
	map = parsing_and_coord(argv);
	if (map == NULL)
	{
		ft_putstr_fd ("\e[3;31m[FDF] This is not enough\e[0m\n", 2);
		exit(1);
	}
	mlx.start = map;
	//set_iso(map);
	map = mlx.start;
	init_and_hook(&mlx);
	init_img(&img, mlx);
	mlx.img = &img;
	draw_all(&img, map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	free_all(&mlx, mlx.start, 1);
}

/*
int main(void)
{
	printf("%s\n", correct_hex("0xff", 4));
	return 0;
}
*/
/*
int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img_vars	img;
	t_coord co;
	t_colors col1;
	t_colors col2;

	col1.a = 1;
	col1.r = 230;
	col1.g = 246;
	col1.b = 3;

	col2.a = 1;
	col2.r = 0;
	col2.g = 0;
	col2.b = 0;

	co.x0 = 200;
	co.y0 = 200;
	co.x1 = 500;
	co.y1 = 1080;
	(void)argc;
	col2 = hex_to_rgb("0xFF0000");
	printf("R : %.2f | G : %2.f | B: %2.f\n", col2.r, col2.g, col2.b);

	//printf("%s\n", correct_hex("0xff", 4));
//	init_and_hook(&mlx);
//	init_img(&img, mlx);
//	mlx.img = &img;
//	drawto(&img, &co, col1, col2);
//	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
//	mlx_loop(mlx.mlx);
//	free_all(&mlx, mlx.start, 1);
}
*/
/*
 *	while (map->next != NULL)
	{
		printf("|\t%.1f\t| ", map->x);
		printf("|\t%.1f\t| ", map->y);
		printf("|\t%d\t| ", map->z);
		printf("|\t%d\t| ", map->real);
		printf("%s\t|\n", map->color);
		map = map->next;
	}
	printf("|\t%.1f\t| ", map->x);
	printf("|\t%.1f\t| ", map->y);
	printf("|\t%d\t| ", map->z);
	printf("|\t%d\t| ", map->real);
	printf("%s\t|\n", map->color);
//	 map->x = (1 / sqrtf(6)) * map->y + 
		(1 / sqrt(6)) * map->x - (2 / sqrt(6)) * map->z;
//	 map->y = (1 / sqrtf(2)) * map->y + (1 / sqrt(2)) * map->x;
//	 map->x = (1 / sqrtf(6)) * map->y + 
		(1 / sqrt(6)) * map->x - (2 / sqrt(6)) * map->z;
//	 map->y = (1 / sqrtf(2)) * map->y + (1 / sqrt(2)) * map->x;
 */