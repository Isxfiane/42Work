/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:26:48 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/26 14:20:12 by sben-rho         ###   ########.fr       */
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

void	free_char(char **result, int limit)
{
	int	i;

	i = 0;
	if (limit == 0)
	{
		while (result[i] != NULL)
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
	else
	{
		while (i < limit)
		{
			free(result[i]);
			i++;
		}
		if (result[i] == NULL)
			free(result);
	}
}

int	ft_close(t_mlx *mlx)
{
	free_all(mlx, mlx->start, 1);
	exit(0);
}

void	*ft_lst_clear(t_map *li)
{
	if (li == NULL)
		return (NULL);
	while (li != NULL)
		ft_lstrm_front(&li);
	return (NULL);
}

void	*ft_free(char *str)
{
	free(str);
	return (NULL);
}