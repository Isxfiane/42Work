/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:49 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/16 12:11:07 by sben-rho         ###   ########.fr       */
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
	if (keycode == 119)
		printf("`w`\n"); /* -1 pour tout les x | Redraw et put_img */
	if (keycode == 97)
		printf("`a`\n"); /* +1 pour tout les y | Redraw et put_img */
	if (keycode == 115)
		printf("`s`\n"); /* +1 pour tout les x | Redraw et put_img */
	if (keycode == 100)
		printf("`d`\n"); /* -1 pour tout les y | Redraw et put_img */
	if (keycode == 65362)
		printf("`up`\n"); /* Multiplicateur de z augmenter | Redraw et put_img */
	if (keycode == 65364)
		printf("`down`\n"); /* Multiplicateur de z deiminuer | Redraw et put_img */
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
