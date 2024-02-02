/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:49:52 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/10 16:55:38 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s[0] == '\0')
	{
		result = (char *) malloc (sizeof(char) * 1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = (char *) malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	result = ft_memcpy(result, s, ft_strlen(s) + 1);
	i = 0;
	while (result[i] != '\0')
	{
		result[i] = f(i, result[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
