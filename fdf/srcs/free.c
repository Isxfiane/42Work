/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:26:48 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/15 15:07:00 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_mlx *mlx, void *start, int i)
{
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	if (i == 1)
		ft_lst_clear(start);
}
