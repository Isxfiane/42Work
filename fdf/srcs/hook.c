/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:49 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/09 17:17:57 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		free_all(mlx, mlx->start, 1);
		exit(0);
	}
	printf("Hey hey, regarde, i know what you do --> [%d]\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void)mlx;
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

int	ft_close(t_mlx *mlx)
{
	free_all(mlx, mlx->start, 1);
	exit(0);
}
