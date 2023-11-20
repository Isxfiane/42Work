/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:03 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/20 18:07:25 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_function(unsigned int *cwrite, char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*cwrite = *cwrite + 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*cwrite = *cwrite + ft_strlen(str);
}

static size_t	writebase(const char *str, unsigned int *cwrite, unsigned int i)
{
	size_t	count;

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
		ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		string_function(cwrite, va_arg(args, char *));
	if (c == 'p')
		print_address(va_arg(args, unsigned long long), cwrite);
	if (c == 'i' || c == 'd')
		ft_putnbr_count(cwrite, (va_arg(args, int)));
	if (c == 'u')
		ft_putunbr_count(cwrite, va_arg(args, unsigned int));
	if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", cwrite);
	if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", cwrite);
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
	va_list			args;

	cwrite = 0;
	i = 0;
	len = ft_strlen(str) + 1;
	va_start(args, str);
	while (i < len)
	{
		i = i + writebase(str, &cwrite, i);
		if (i > len || i + 1 > len)
			break ;
		after_sign(&cwrite, args, str[i + 1]);
		i = i + 2;
	}
	va_end(args);
	return (cwrite);
}
