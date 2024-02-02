/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:20:47 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/10 13:23:02 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*temp;
	const char		*srcpy;
	size_t			i;

	temp = (char *)dest;
	srcpy = (char *)src;
	i = 0;
	if (n <= 0)
		return (dest);
	if (src > dest)
		ft_memcpy(temp, src, n);
	else
	{
		i = n - 1;
		while (i != 0)
		{
			temp[i] = srcpy[i];
			i--;
		}
		temp[0] = srcpy[0];
	}
	return (temp);
}
