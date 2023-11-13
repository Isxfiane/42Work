/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:33:56 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/13 13:27:56 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*temp;
	unsigned int	i;
	char			set;

	if (!s)
		return (NULL);
	temp = (char *)s;
	set = c;
	i = 0;
	while (i < n)
	{
		if (temp[i] == set)
			return (&temp[i]);
		else
			i++;
	}
	return (NULL);
}
