/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:31:26 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/09 12:43:52 by sben-rho         ###   ########.fr       */
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
	char		**result;
	char		*temp;
	char		buffer[51];
	int			fd;
	ssize_t		k;

	if (check_file(argv) == -1)
		return (NULL);
	fd = open_file(argv);
	if (fd == -1)
		return (NULL);
	k = 1;
	temp = NULL;
	while (k != 0)
	{
		k = read(fd, buffer, 50);
		if (k <= 0)
			break ;
		buffer[k] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	result = ft_split(temp, ' ');
	free(temp);
	close(fd);
	return (result);
}
