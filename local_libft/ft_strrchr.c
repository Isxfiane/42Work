/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:21:39 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/13 13:23:04 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*scopy;
	long int		i;
	long int		save;
	unsigned char	set;

	i = 0;
	save = -1;
	if (!s)
		return (NULL);
	scopy = (char *)s;
	set = c;
	if (set == '\0')
		return (&scopy[ft_strlen(scopy)]);
	while (scopy[i] != '\0')
	{
		if (scopy[i] == set)
			save = i;
		i++;
	}
	if (save != -1)
		return (&scopy[save]);
	return (NULL);
}
