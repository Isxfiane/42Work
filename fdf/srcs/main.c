/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:25:19 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/09 17:18:53 by sben-rho         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	mlx;

	(void)argc;
	map = parsing_and_coord(argv);
	mlx.start = map;
	init_and_hook(&mlx);
	mlx_loop(mlx.mlx);
	free_all(&mlx, mlx.start, 1);
}
