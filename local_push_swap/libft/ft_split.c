/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:01:57 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/15 13:08:37 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_of_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && count == 0)
			return (0);
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			count++;
	}
	if (s[0] == '\0')
		return (0);
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

static char	**fillsplit(char **result, const char *s, unsigned int n, char c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	save;

	i = 0;
	k = 0;
	while (i != n + 1 && s[k] != '\0')
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		save = k;
		if (s[save] == '\0')
			break ;
		while (s[k] != c && s[k] != '\0')
			k++;
		result[i] = ft_substr(s, save, k - save);
		if (result[i] == NULL)
			return (freeall(result, i));
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
	if (s[0] == '\0')
	{
		result[0] = NULL;
		return (result);
	}
	return (fillsplit(result, s, n, c));
}
