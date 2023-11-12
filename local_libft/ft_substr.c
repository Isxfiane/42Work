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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	result = (char *) malloc (sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}
