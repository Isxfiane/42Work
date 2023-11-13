/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:24:23 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/13 13:56:12 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*dest;
	unsigned int	i;
	unsigned char	set;

	if (!s)
		return (NULL);
	set = c;
	dest = (char *)s;
	i = -1;
	while (dest[++i] != '\0')
	{
		if (dest[i] == set)
			return (&dest[i]);
	}
	if (dest[i] == '\0' && set == '\0')
		return (&dest[i]);
	return (NULL);
}
