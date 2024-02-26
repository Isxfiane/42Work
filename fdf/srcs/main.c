/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:25:19 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/26 16:17:55 by sben-rho         ###   ########.fr       */
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
		return (ft_lst_clear(map));
	}
	ft_lst_reverse(&map);
	calculate_coord(map);
	close(fd);
	return (map);
}

void	init_and_hook(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		ft_lst_clear(mlx->start);
		exit(1);
	}
	mlx->win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "fdf");
	if (mlx->win == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		ft_lst_clear(mlx->start);
		exit(1);
	}
	mlx_hook(mlx->win, 02, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, ft_close, mlx);
}

void	init_img(t_img_vars *img, t_mlx mlx)
{
	img->img = mlx_new_image(mlx.mlx, HEIGHT, WIDTH);
	if (img == NULL)
	{
		free_all(&mlx, mlx.start, 1);
		exit(1);
	}
	img->buffer = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
}

void	set_iso(t_map *map)
{
	float	tempy;
	float	tempx;

	while (map != NULL)
	{
		tempy = -(1 / sqrt(6)) * map->y
			+ (1 / sqrt(6)) * map->x - (2 / sqrt(6)) * map->z;
		tempx = (1 / sqrt(2)) * map->y + (1 / sqrt(2)) * map->x;
		map->x = tempy + 700;
		map->y = tempx - 100;
		map = map->next;
	}
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
		ft_putstr_fd ("\e[3;31m[FDF] This is not enough.\e[0m\n", 2);
		exit(1);
	}
	mlx.start = map;
	set_iso(map);
	map = mlx.start;
	init_and_hook(&mlx);
	init_img(&img, mlx);
	mlx.img = &img;
	draw_all(&img, map, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	free_all(&mlx, mlx.start, 1);
}
