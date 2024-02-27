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

void	quit(char **result, t_map **map)
{
	free_char(result, 0);
	ft_lst_clear(*map);
	exit(1);
}

int	create_backup(char **result, int k, int i, t_map **map)
{
	char	**backup;

	backup = malloc(sizeof(char *) * 4);
	if (!backup)
		return (-1);
	backup[0] = ft_strndup(result[i], k);
	if (!backup[0])
		return (-1);
	backup[1] = ft_strdup("|");
	if (!backup[1])
		return (-1);
	backup[2] = ft_substr(result[i], k + 1,
			ft_strlen(result[i]) - (k + 1));
	if (!backup[2])
		return (-1);
	backup[3] = NULL;
	fill_list(backup, map);
	free_char(backup, 3);
	return (0);
}

void	basic_case(int k, char **result, int i, t_map **map)
{
	int	len;

	if (k != -1)
	{
		len = ft_strlen(result[i]) - k;
		if (ft_lstadd_front(map, ft_atoi(result[i]),
			ft_substr(result[i], k + 1, len - 1), 1) == -1)
				quit(result, map);
	}
	else if (result[i][0] != '\0')
	{
		if (ft_lstadd_front(map, ft_atoi(result[i]), NULL, 1) == -1)
			quit(result, map);
	}
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
			if (ft_lstadd_front(map, ft_atoi(result[i]), NULL, -1) == -1)
				quit(result, map);
			i++;
		}
		k = ft_strfind(result[i], '\n');
		if (k != -1)
		{
			if (create_backup(result, k, i, map) == -1)
				quit(result, map);
			i++;
			if (result[i] == NULL)
				break ;
		}
		k = ft_strfind(result[i], ',');
		basic_case(k, result, i, map);
		i++;
	}
}
