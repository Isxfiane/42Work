/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:31:26 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/15 14:47:31 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *argv)
{
	size_t	len;

	if (!argv || argv[0] == '\0')
	{
		ft_putstr_fd("\e[3;31m[FDF] Huh ? No File, No map.\e[0m\n", 2);
		exit(1);
	}
	len = ft_strlen(argv);
	if (ft_strnstr(argv, ".fdf", len) == NULL)
	{
		ft_putstr_fd("\e[3;31m[FDF] Oh, Watch out, "
			"i need a '.fdf' file.\e[0m\n", 2);
		exit(1);
	}
}

int	open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("\e[3;31m[FDF] Error when opening the file, "
			"check it. (See details below)\e[0m\n\t");
		exit(1);
	}
	return (fd);
}

char	**parsing(int fd)
{
	char		**result;
	char		*temp;

	temp = get_next_line(fd);
	result = ft_split(temp, ' ');
	free(temp);
	return (result);
}
