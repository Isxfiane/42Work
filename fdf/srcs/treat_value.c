/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:25 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/23 13:32:08 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_backup(char **result, int k, int i, t_map **map)
{
	char	**backup;

	backup = malloc(sizeof(char *) * 4);
	backup[0] = ft_strndup(result[i], k);
	backup[1] = ft_strdup("|");
	backup[2] = ft_substr(result[i], k + 1,
			ft_strlen(result[i]) - (k + 1));
	backup[3] = NULL;
	fill_list(backup, map);
	free_char(backup, 3);
}

void	basic_case(int k, char **result, int i, t_map **map)
{
	int	len;

	if (k != -1)
	{
		len = ft_strlen(result[i]) - k;
		ft_lstadd_front(map, ft_atoi(result[i]),
			ft_substr(result[i], k + 1, len - 1), 1);
	}
	else if (result[i][0] != '\0')
		ft_lstadd_front(map, ft_atoi(result[i]), NULL, 1);
}

void	fill_list(char **result, t_map **map)
{
	int		i;
	int		k;

	i = 0;
	while (result[i] != NULL)
	{
		if (result[i][0] == '|')
		{
			ft_lstadd_front(map, ft_atoi(result[i]), NULL, -1);
			i++;
		}
		k = ft_strfind(result[i], '\n');
		if (k != -1)
		{
			create_backup(result, k, i, map);
			i++;
			if (result[i] == NULL)
				break ;
		}
		k = ft_strfind(result[i], ',');
		basic_case(k, result, i, map);
		i++;
	}
}
