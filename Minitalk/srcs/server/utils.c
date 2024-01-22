#include "minitalk.h"

int ft_strstr(const char *str, const char *tofind)
{
	int     i;
	int     f;
	int     k;

	i = 0;
	while (str[i] != '\0')
	{
		f = 0;
		k = 0;
		while (tofind[f] != '\0')
		{
			if (str[i + f] == tofind[k])
				k++;
			else
				break ;
			f++;
			if (k == ft_strlen(tofind))
				return (i);
		}
		i++;
	}
	return (-1);
}

char one_or_zero(int a)
{
	if (a == 1)
		return ('1');
	else
		return ('0');
}

int    get_index(char c, const char *base)
{
	int    i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int   ft_atoi_base(char *str, char *base)
{
	int    sign;
	int    i;
	int   nb;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == 32))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (get_index(str[i], base) != -1)
	{
		nb = nb * ft_strlen(base) + get_index(str[i], base);
		i++;
	}
	return (sign * nb);
}

char	*createbuff(char *buffer, ssize_t len)
{
	int i;

	i = 0;
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	while (i < len)
	{
		buffer[i] = '2';
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*savechar(char *result, int c, int *n)
{
	int i;

	i = 0;
	printf("%d | %c\n", c, c);
	if (c == 0)
	{
		printf("%s\n", result);
		free(result);
		*n = 0;
		return (NULL);
	}
	while (result[i] != '2')
		i++;
	if (result[i] != '\0')
		result[i] = c;
	return (result);
}

char	*cleanbuffer(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\0')
	{
		buffer[i] = '2';
		i++;
	}
	return (buffer);
}


char 	*copyandclear(char *buffer, int *n, char *result)
{
	int			pos;
	ssize_t 	i;
	char		*str;

	pos = ft_strstr(buffer, "100000000");
	str = malloc(sizeof(char) * (pos + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < pos)
		str[i] = buffer[i];
	str[i] = '\0';
	if (*n == 0)
	{
		i = ft_atoi_base(str, "01");
		result = createbuff(result, i);
		*n = 1;
	}
	else
		savechar(result, ft_atoi_base(str, "01"), n);
	buffer = cleanbuffer(buffer);
	free(str);
	return (result);
}
