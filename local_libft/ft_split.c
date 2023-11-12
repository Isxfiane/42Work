/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:01:57 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/12 11:46:20 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_of_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 1;
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
	return (count);
}

static char	**fill_split(char **tab, unsigned int count, char *cpy, char c)
{
	unsigned int	i;
	unsigned int	k;
	size_t			len;

	i = 0;
	k = -1;
	len = ft_strlen(cpy);
	while (i < len)
	{
		count = i;
		while (cpy[i] != c && i < len)
			i++;
		k++;
		tab[k] = ft_substr(cpy, count, i - count);
		if (tab[k] == NULL)
			return (NULL);
		while (cpy[i] == c && i < len)
			i++;
	}
	k++;
	tab[k] = NULL;
	return (tab);
}

static void	*freeall(char *cpy, char **result)
{
	free(cpy);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			*cpy;
	char			charset[5];
	unsigned int	count;
	char			**result;

	if (s == NULL)
		return (NULL);
	cpy = (char *)s;
	ft_memset(charset, c, 4);
	cpy = ft_strtrim(cpy, charset);
	if (cpy == NULL)
		return (NULL);
	count = nb_of_split(cpy, c);
	result = (char **) malloc (sizeof(char *) * (count + 1));
	if (result == NULL)
		return (freeall(cpy, result));
	result = fill_split(result, count, cpy, c);
	if (result == NULL)
	{
		freeall(cpy, result);
		return (NULL);
	}
	free(cpy);
	return (result);
}
