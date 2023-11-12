/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:38:03 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/12 11:45:24 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*error(void)
{
	char	*error;

	error = (char *) malloc (sizeof(char) * 1);
	if (error == NULL)
		return (NULL);
	error[0] = '\0';
	return (error);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;
	unsigned int	k;
	unsigned int	count;

	i = start;
	k = 0;
	count = 0;
	if (start > ft_strlen(s) || s[0] == '\0')
		return (error());
	cpy = (char *) malloc (sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	while ((s[i] != '\0') && (count < len))
	{
		cpy[k] = s[i];
		i++;
		k++;
		count++;
	}
	cpy[k] = '\0';
	return (cpy);
}
