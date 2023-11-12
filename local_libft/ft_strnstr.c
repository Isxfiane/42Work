/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:25:31 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/12 11:50:07 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	unsigned int	k;
	size_t			lenlittle;
	char			*bigcopy;

	i = 0;
	k = 0;
	bigcopy = (char *)big;
	lenlittle = ft_strlen(little);
	if (little[0] == '\0')
		return (bigcopy);
	while (i < len && (big[i] != '\0'))
	{
		if (k == lenlittle)
			return (&bigcopy[i - k]);
		if (big[i] == little[k])
			k++;
		else
			k = 0;
		i++;
	}
	 if (k == lenlittle)
        return (&bigcopy[i - k]);
    return (NULL);
}
