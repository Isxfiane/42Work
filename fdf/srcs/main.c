/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:25:19 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/12 18:08:13 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*parsing_and_coord(char **argv)
{
	char	**result;
	t_map	*map;

	result = parsing(argv[1]);
	if (!result)
		return (NULL);
	map = NULL;
	fill_list(result, &map);
	calculate_coord(map);
	free_char(result, 0);
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

void	free_all(t_mlx *mlx, void *start, int i)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	if (i == 1)
		ft_lst_clear(start);
}

void	test(t_map *map)
{
	while (map->next != NULL)
	{
		// map->x = (1 / sqrtf(6)) * map->y + (1 / sqrt(6)) * map->x - (2 / sqrt(6)) * map->z;
		// map->y = (1 / sqrtf(2)) * map->y + (1 / sqrt(2)) * map->x;
		map->x = (map->x - map->z)/sqrt(2);
		map->y = (map->x + 2 * map->y + map->z) / sqrt(6);
		map = map->next;
	}
	// map->x = (1 / sqrtf(6)) * map->y + (1 / sqrt(6)) * map->x - (2 / sqrt(6)) * map->z;
	// map->y = (1 / sqrtf(2)) * map->y + (1 / sqrt(2)) * map->x;
	map->x = (map->x - map->z)/sqrt(2);
	map->y = (map->x + 2 * map->y + map->z) / sqrt(6);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		mlx;
	t_img_vars	img;
	t_colors	color;
	t_map		*map2;

	color.a = 1;
	color.r = 164;
	color.g = 255;
	color.b = 164;
	(void)argc;
	map = parsing_and_coord(argv);
	if (map == NULL)
		exit(1);
	mlx.start = map;
	map = mlx.start;
	test(map);
	map = mlx.start;
		while (map->next != NULL)
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
	map = mlx.start;
	init_and_hook(&mlx);
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.buffer = mlx_get_data_addr(img.img, &img.pixel_bits, &img.line_bytes, &img.endian);
	draw_all(&img, map, color, mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	free_all(&mlx, mlx.start, 1);
}
