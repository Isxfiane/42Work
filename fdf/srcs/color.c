/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:27:35 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/26 14:32:14 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_colors(float r, float g, float b, t_colors *col)
{
	if (r != -2)
		col->r = r;
	if (g != -2)
		col->g = g;
	if (b != -2)
		col->b = b;
}

void	add_value(float f, t_colors *col)
{
	if (col->r == -1)
		col->r = f;
	else if (col->g == -1)
		col->g = f;
	else if (col->b == -1)
		col->b = f;
}

char	*correct_hex(char *hex, int diff)
{
	int		i;
	char	*result;
	char	*temp;

	i = 2;
	result = malloc(sizeof(char) * (ft_strlen(hex) + diff));
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	while (diff > 0)
	{
		result[i] = '0';
		i++;
		diff--;
	}
	result[i] = '\0';
	temp = ft_substr(hex, 2, ft_strlen(hex) - 2);
	if (!temp)
		return (ft_free(result));
	result = ft_strjoin(result, temp);
	free(temp);
	return (result);
}

int	find_rbg(t_colors *result, char *hex, int i, int n)
{
	char	*temp;

	fill_colors(-1, -1, -1, result);
	ft_lower_string(hex);
	i = 2;
	while (hex[i] != '\0')
	{
		if (hex[i] == '0')
			add_value(0, result);
		else
		{
			temp = char_to_string(hex[i], hex[i + 1]);
			if (!temp)
				return (-1);
			add_value (ft_atoi_base(temp, "0123456789abdef"), result);
			free(temp);
		}
		if (hex[i + 1] != '\0')
			i = i + 2;
		else
			break ;
	}
	if (n == 1)
		free(hex);
	return (0);
}

t_colors	*hex_to_rgb(char *hex)
{
	t_colors	*result;
	int			i;
	int			n;

	n = 0;
	result = malloc(sizeof(t_colors));
	i = ft_strlen(hex);
	if (i < 4 || hex[0] != '0' || hex[1] != 'x')
	{
		fill_colors(0, 255, 150, result);
		return (result);
	}
	if (i < 8)
	{
		hex = correct_hex(hex, 6 - (i - 2));
		if (hex == NULL)
			return (NULL);
		n = 1;
	}
	if (find_rbg(result, hex, i, n) == -1)
		return (NULL);
	while (result->b == -1)
		add_value(0, result);
	return (result);
}
