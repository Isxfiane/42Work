#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	b;
	char c = 'z';
	char *strff = "Zebi il a ";
	char *str2 = " gun ce fou";
	char *str3 = "pitain de merde";

	char *test = "Alala apres 141 essai haha0x7ffd8bc2fea0haha sa marche & 2a";

	b = 2;


	char cff = 'z';
	char *str = "Alala apres";
	char add = 'a';
	int d = 556;
	int i = 762;
	unsigned int u = 141;
	int x = 42;
	int X = 42;


	ft_putchar_fd('\n', 1);
//  printf(" | [%d]\n", ft_printf("Oh %s%d", str, b));
 	printf("\n[%d]\n", ft_printf("%s %u essai haha%phaha sa marche %X", str, u, &add, X));
}
