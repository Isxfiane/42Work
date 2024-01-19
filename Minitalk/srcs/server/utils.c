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
