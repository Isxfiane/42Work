/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:25:31 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/13 14:39:37 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	unsigned int	k;
	size_t			lenlittle;
	char			*bigcopy;

	i = -1;
	k = 0;
	bigcopy = (char *)big;
	lenlittle = ft_strlen(little);
	if (!little)
		return (bigcopy);
	while (++i < len && (big[i] != '\0'))
	{
		if (k == lenlittle)
			return (&bigcopy[i - k]);
		if (big[i] == little[k])
			k++;
		else
        {
            i = i - k;
			k = 0;
        }
	}
	if (k == lenlittle)
		return (&bigcopy[i - k]);
	return (NULL);
}
