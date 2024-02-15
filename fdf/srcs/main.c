/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:25:19 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/15 15:37:22 by sben-rho         ###   ########.fr       */
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
	calculate_coord(map);
	close(fd);
	return (map);
}

void	init_and_hook(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fdf");
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, ft_close, mlx);
}

void	init_img(t_img_vars *img, t_mlx mlx)
{
	img->img = mlx_new_image(mlx.mlx, 1920, 1080);
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
	img->color.a = 1;
	img->color.r = 127;
	img->color.g = 17;
	img->color.b = 224;
}

void	set_iso(t_map *map)
{
	while (map->next != NULL)
	{
		map->x = (map->x - map->z) / sqrt(2);
		map->y = (map->x + 2 * map->y + map->z) / sqrt(6);
		map = map->next;
	}
	map->x = (map->x - map->z) / sqrt(2);
	map->y = (map->x + 2 * map->y + map->z) / sqrt(6);
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
	map = mlx.start;
	set_iso(map);
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