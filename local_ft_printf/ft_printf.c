/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:03 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/17 15:01:17 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_address(va_list args, unsigned int *cwrite)
{
	ft_putstr_fd("0x", 1);
	*cwrite = *cwrite + 2;
	ft_putnbr_base((size_t)va_arg(args, long long int), "0123456789abcdef", cwrite);
}
static unsigned int	writebase(const char *str, unsigned int *cwrite, unsigned int i)
{
	int count;

	count = 0;
	while (str[i] != '\0' && str[i] != '%')
	{
		ft_putchar_fd(str[i], 1);
		i++;
		count++;
	}
	*cwrite = *cwrite + count;
	return (count);
}

static void	after_sign(unsigned int *cwrite, va_list args, char c)
{
	if (c == 'c')
		ft_putchar_fd(c, 1);
	if (c == 's')
		string_function(cwrite, args);
 	if (c == 'p')
		print_address(args, cwrite);
	// if (c == 'd')
	// 	print_float(va_arg(args, double), cwrite);
 	if (c == 'i')
	 	ft_putnbr_count(cwrite, args);
	// if (c == 'u')
	// A voir en fonction diff (Float Positive ?)
	if (c == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef", cwrite);
	if (c == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", cwrite);
	if (c == '%')
		ft_putchar_fd('%', 1);
	if (c == 'c' || c == '%')
		*cwrite = *cwrite + 1;
}

int	ft_printf(const char *str, ...)
{
	unsigned int	cwrite;
	unsigned int	i;
	unsigned int	len;
	va_list args;
	
	cwrite = 0;
	i = 0;
	len = ft_strlen(str) + 1;
	va_start(args, str);
	while (i < len)
	{
		i = i + writebase(str, &cwrite, i);
		if (i > len || i + 1 > len)
			break;	
			after_sign(&cwrite, args, str[i + 1]);
			i = i + 2;
	}
	va_end(args);
	return (cwrite);
}

//3099999904632568


	int main()
	{
	float a;
	int b;
	char *str = "Zebi il a ";
	char *str2 = " gun ce fou";

	a = 556.556;
	printf(" | [%d]\n", ft_printf("Oh %s%d%s il a cru akimbo ici ouuu", str, a, str2));
	printf("\n[%f]\n", a);
}