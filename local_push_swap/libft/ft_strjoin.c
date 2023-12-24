/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:05:46 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/11 13:30:00 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			lens1;
	size_t			lens2;
	char			*join;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen (s2);
	join = (char *) malloc (sizeof(char) * (lens1 + lens2) + 1);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, lens1 + 1);
	ft_strlcat(join, s2, lens1 + lens2 + 1);
	return (join);
}
