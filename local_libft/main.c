
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*temp;
	unsigned int	i;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = ft_strlen(s);
	i = 0;
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len == ft_strlen(s) + 1)
			result = (char *) malloc (sizeof(char) * ((len)));
	else if (len <= ft_strlen(s))
		result = (char *) malloc (sizeof(char) * ((len + 1))); 
	else
		result = (char *) malloc (sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}

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
static int	is_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
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
static int	fill_split(char **tab, unsigned int count, char *cpy, char c)
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
			return (k);
		while (cpy[i] == c && i < len)
			i++;
	}
	k++;
	tab[k] = NULL;
	return (-1);
}

static void	*freeall(char *cpy, char **result, long long int n)
{
	unsigned int	i;

	i = 0;
	free(cpy);
	while (n + 1 != i)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			*cpy;
	char			charset[5];
	unsigned int	count;
	char			**result;
	long long int	n;

	if (!s || s[0] == '\0')
		return (NULL);
	cpy = (char *)s;
	n = 0;
	ft_memset(charset, c, 5);
	cpy = ft_strtrim(cpy, charset);
	if (cpy == NULL)
		return (NULL);
	count = nb_of_split(cpy, c);
	result = (char **) malloc (sizeof(char *) * (count + 1));
	if (result == NULL)
		return (freeall(cpy, result, n));
	n = fill_split(result, count, cpy, c);
	if (n != -1)
		return (freeall(cpy, result, n));
	free(cpy);
	return (result);
}
















int main()
{
	ft_split("a a a a a a", ' ');
    return 0;
}