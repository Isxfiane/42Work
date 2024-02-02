/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:22:40 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/26 11:25:05 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_str2cpy(char *src, char *src2, char *dest, ssize_t lenbuff)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (src != NULL && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (k != lenbuff)
	{
		dest[i] = src2[k];
		k++;
		i++;
		if (dest[i - 1] == '\n')
			break ;
	}
	dest[i] = '\0';
	return (dest);
}
