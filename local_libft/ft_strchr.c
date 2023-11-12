/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:24:23 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/11 10:56:29 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*scopy;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	scopy = (char *)s;
	if (scopy[0] == '\0')
		return ((char *)s);
	while (scopy[i] != '\0')
	{
		if (scopy[i] == c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if (scopy[i] == '\0' && c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
