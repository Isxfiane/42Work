
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main()
{
	int		i;
	char	**tab;
	i = -1;
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	while (tab[++i] != NULL)
		printf("%s\n", tab[i]);
}

