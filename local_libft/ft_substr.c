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
	char			*cpy;
	unsigned int	i;
	unsigned int	k;
	unsigned int	count;
	char			*error;

	i = start;
	k = -1;
	count = -1;
	error = (char *) malloc (sizeof(char) * 1);
	error[0] = '\0';
	if (error == NULL)
		return (NULL);
	if (start > ft_strlen(s) + 1 || s[0] == '\0')
		return (error);
	cpy = (char *) malloc (sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	while ((s[i] != '\0') && (++count < len))
	{
		cpy[++k] = s[i];
		i++;
	}
	cpy[k] = '\0';
	return (cpy);
}
