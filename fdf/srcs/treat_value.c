/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:25 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/08 15:52:54 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstadd_back(t_map **li, int x, char *color, int real)
{
	t_map	*element;
	t_map	*temp;

	element = malloc(sizeof(*element));
	if (!element)
		return ;
	element->z = x;
	element->color = color;
	element->real = real;
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

char	*ft_strndup(const char *s, int n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *) malloc (sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	fill_list(char **result, t_map **map)
{
	int	i;
	int	k;
	int	len;
	char **backup;

	i = 0;
	k = 0;
	while (result[i] != NULL)
	{
		if (result[i][0] == '|')
		{
			ft_lstadd_back(map, ft_atoi(result[i]), NULL, -1);
			i++;
			if (result[i] == NULL)
				break;
		}
		k = ft_strfind(result[i], '\n');
		if (k != -1)
		{
			backup = malloc(sizeof(char *) * 4);
			backup[0] = ft_strndup(result[i], k);
			backup[1] = ft_strdup("|");
			backup[2] = ft_substr(result[i], k + 1, ft_strlen(result[i]) - (k + 1));
			backup[3] = NULL;
			fill_list(backup, map);
			free_char(backup, 3);
			i++;
			if (result[i] == NULL)
				break ;
		}
		k = ft_strfind(result[i], ',');
		if (k != -1)
		{
			len = ft_strlen(result[i]) - k;
			ft_lstadd_back(map, ft_atoi(result[i]),
				ft_substr(result[i], k + 1, len - 1), 1);
		}
		else if (result[i][0] != '\0')
			ft_lstadd_back(map, ft_atoi(result[i]),  NULL, 1);
		i++;
	}
}
