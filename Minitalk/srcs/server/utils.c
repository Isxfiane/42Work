#include "minitalk.h"

int ft_strstr(const char *str, const char *tofind)
{
	int i;
	int j;
	int save;

	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == tofind[j])
		{
			if (j == 0)
				save = i;
			j++;
		}
		else if (str[i] != tofind[j] && j != 0)
		{
			i = save;
			j = 0;
		}
		if (j == ft_strlen(tofind))
			return (save);
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

int    get_index(char c, char *base)
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

int    ft_atoi_base(char *str, char *base)
{
	int    sign;
	int    i;
	int    nb;

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