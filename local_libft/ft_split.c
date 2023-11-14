/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:01:57 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/14 17:59:04 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	nb_of_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (count == 0)
		return (1);
	return (count);
}

static void	*freeall( char **result, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n + 1 > i)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**fillsplit(char **result, const char *s, unsigned int n, char c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	save;

	i = 0;
	k = 0;
	while (i != n + 1)
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		save = k;
		if (s[save] == '\0')
			break ;
		while (s[k] != c && s[k] != '\0')
			k++;
		if (k - save > 0)
		{
			result[i] = ft_substr(s, save, k - save);
			if (result[i] == NULL)
				return (freeall(result, i));
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	n;
	char			**result;

	if (!s)
		return (NULL);
	n = nb_of_split(s, c);
	result = (char **) malloc (sizeof(char *) * (n + 1));
	if (!result)
		return (NULL);
	return (fillsplit(result, s, n, c));
}
