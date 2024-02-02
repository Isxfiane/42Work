/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:14:47 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/09 15:33:31 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*temp;
	char			*srcpy;
	unsigned int	i;

	temp = (char *)dest;
	srcpy = (char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = srcpy[i];
		i++;
	}
	return (dest);
}
