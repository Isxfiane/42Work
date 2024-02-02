/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:48:36 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/13 15:18:58 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*result;
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;

	start = 0;
	if (!s1)
		return (NULL);
	while (is_set(s1[start], set) == 1)
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = (ft_strlen(s1)) - 1;
	while (is_set(s1[end], set) == 1)
		end--;
	len = (end - start) + 1;
	result = ft_substr(s1, start, len);
	if (result == NULL)
		return (NULL);
	return (result);
}
