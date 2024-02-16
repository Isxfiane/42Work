/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:22:17 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/09 13:26:40 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_linelen(t_map *li)
{
	int	size;

	size = 0;
	while (li != NULL && li->real != -1)
	{
		size++;
		li = li->next;
	}
	return (size);
}

char	*ft_strndup(const char *s, unsigned int n)
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
