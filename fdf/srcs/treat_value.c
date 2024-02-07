/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:25 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/07 12:37:14 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstadd_back(t_map **li, int x, char *color)
{
	t_map	*element;
	t_map	*temp;

	element = malloc(sizeof(*element));
	if (!element)
		return ;
	element->z = x;
	element->color = color;
	element->next = NULL;
	if (*li == NULL)
	{
		*li = element;
		return ;
	}
	temp = *li;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = element;
}

void	fill_list(char **result, t_map **map)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	k = 0;
	while (result[i] != NULL)
	{
		k = ft_strfind(result[i], ',');
		if (k != -1)
		{
			len = ft_strlen(result[i]) - k;
			ft_lstadd_back(map, ft_atoi(result[i]),
				ft_substr(result[i], k + 1, len));
		}
		else
			ft_lstadd_back(map, ft_atoi(result[i]), NULL);
		i++;
	}
}
