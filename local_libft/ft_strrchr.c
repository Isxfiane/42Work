/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:21:39 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/10 17:18:04 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*scopy;
	unsigned int	i;
	long int		save;

	i = 0;
	save = -1;
	scopy = (char *)s;
	if (scopy[0] == '\0')
		return (scopy);
	while (scopy[i] != '\0')
	{
		if (scopy[i] == c)
			save = i;
		i++;
	}
	if (scopy[i] == '\0' && c == '\0')
		return (&scopy[i]);
	if (save != -1)
		return (&scopy[save]);
	return (NULL);
}
