/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:21:10 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/10 14:56:09 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	lensrc;

	i = 0;
	len = 0;
	lensrc = ft_strlen(src);
	if (size == 0)
		return (len + lensrc);
	while (dst[i] != '\0' && i < size)
		i++;
	len = i;
	while (src[i - len] != '\0' && i < size - 1)
	{
		dst[i] = src[i - len];
		i++;
	}
	if (len < size)
		dst[i] = '\0';
	return (len + lensrc);
}
