/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:31:26 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/07 14:19:15 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(char *argv)
{
	size_t	len;

	if (!argv || argv[0] == '\0')
		return (1);
	len = ft_strlen(argv);
	if (ft_strnstr(argv, ".fdf", len) == NULL)
	{
		ft_putstr_fd("\e[3;31m[FDF] Oh, Watch out, "
			"i need a '.fdf' file.\e[0m\n", 2);
		return (-1);
	}
	else
		return (1);
}

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		perror("\e[3;31m[FDF] Error when opening the file, "
			"check it. (See details below)\e[0m\n\t");
	return (fd);
}

char	**parsing(char *argv)
{
	char	**result;
	char	*temp;
	char	*buffer;
	int		fd;

	if (check_file(argv) == -1)
		return (NULL);
	fd = open_file(argv);
	if (fd == -1)
		return (NULL);
	buffer = get_next_line(fd);
	if (!buffer)
	{
		ft_putstr_fd("\e[3;31m[FDF] This is an empty file, "
			 "impossible to make a map\e[0m\n", 2);
		return (NULL);
	}
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break;
		buffer = ft_strjoin(buffer, temp);
		free(temp);
		if (!buffer)
			perror("\e[3;31mMalloc Fail\e[0m\n\t");
	}
	free(temp);
	result = ft_split(buffer, ' ');
	free(buffer);
	close(fd);
	return (result);
}
