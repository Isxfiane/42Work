/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:24:13 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/22 13:29:17 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *save_buffer(char *buffer, char *result, int lenbuff, int *n)
{
	char	*temp;
	int		lenr;
	int		i;

	if (lenbuff != BUFFER_SIZE)
		*n = -1;
	i = 0;
	lenr = ft_strlen(result);
	temp = (char *) malloc (sizeof(char) * lenr + 1);
	temp = ft_strncpy(result, temp, lenr);
	free(result);
	i = ft_strchr(buffer, '\n');
	if (i != 0)
	{
		result = (char *) malloc ((sizeof(char) * i) + (sizeof(char) * ft_strlen(temp)) +1);
		result = ft_str2cpy(temp, buffer, result, i);
	}
	else
	{
		result = (char *) malloc ((sizeof(char) * lenbuff) + (sizeof(char) * ft_strlen(temp)) +1);
		result = ft_str2cpy(temp, buffer, result, lenbuff);
	}
	free(temp);
	return (result);
}

char	*get_next_line(int fd)
{
	int				n;
	static char		*buffer;
	char			*result;
	int				lenbuff;
	
	n = 0;
	result = (char *) malloc (sizeof(char) * 1);
	result = 0; 
	while (n != -1)
	{
		lenbuff = read(fd, buffer, BUFFER_SIZE);
		printf("Read good\n pour lenbuuf = %d\n", lenbuff);
		if (lenbuff == -1)
		{
			printf("in IF\n");
			free(result);
			return (NULL);
		}
		printf("Hors if\n");
		result = save_buffer(buffer, result, lenbuff, &n);
	}
	printf("Hors boucle\n");
	return (result);
}
