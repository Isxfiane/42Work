/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:49 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/02 14:54:13 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		printf("\nOk je me casse.\n");
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(-1);
	}
	printf("Hey hey, regarde, i know what you do --> [%d]\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1)
		printf("Clique gauche\n");
	else if (button == 3)
		printf("Clique droite\n");
	else if (button == 2)
		printf("Clique middle\n");
	else
		printf("Scroll\n");
	printf("I see youuu yep, t'es la batard [%d][%d]\n", x, y);
	return (0);
}
