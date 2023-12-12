/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:20 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/22 13:28:29 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *src, char *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_str2cpy(char *src, char *src2, char *dest, int lenbuff)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (src[i] != '\0')
	{
		dest[i]	= src[i];
		i++;
	}
	while (k != lenbuff)
	{
		dest[i] = src2[k];
		k++;
		i++;
		if (dest[i- 1] == '\n')
			break ;
	}		
	dest[i] = '\0';
	return (dest);
}

int ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}