/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:05:46 by sben-rho          #+#    #+#             */
/*   Updated: 2024/02/26 14:17:14 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t			lens1;
	size_t			lens2;
	char			*join;
	char			*temp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	temp = ft_strdup(s1);
	if (!temp)
		return (NULL);
	free(s1);
	lens1 = ft_strlen(temp);
	lens2 = ft_strlen(s2);
	join = (char *) malloc (sizeof(char) * (lens1 + lens2) + 1);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, temp, lens1 + 1);
	ft_strlcat(join, s2, lens1 + lens2 + 1);
	free(temp);
	return (join);
}
