/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:30 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/20 18:09:14 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(int nb)
{
	int				i;
	unsigned int	abs;

	if (nb < 0)
		abs = nb * -1;
	else
		abs = nb;
	i = 1;
	while (abs > 9)
	{
		abs = abs / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_count(unsigned int *cwrite, int nb)
{
	int	len;

	len = get_size(nb);
	ft_putnbr_fd(nb, 1);
	if (nb >= 0)
		*cwrite = *cwrite + len;
	else
		*cwrite = *cwrite + len + 1 ;
}

void	ft_putnbr_base(unsigned long long n, char *base, unsigned int *cwrite)
{
	unsigned int	k;

	k = ft_strlen(base);
	if (n >= k)
	{
		ft_putnbr_base(n / k, base, cwrite);
		ft_putnbr_base(n % k, base, cwrite);
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*cwrite = *cwrite + 1;
	}
}

void	print_address(unsigned long long add, unsigned int *cwrite)
{
	if (add == 0)
	{
		string_function(cwrite, "(nil)");
		return ;
	}
	ft_putstr_fd("0x", 1);
	*cwrite = *cwrite + 2;
	ft_putnbr_base(add, "0123456789abcdef", cwrite);
}

void	ft_putunbr_count(unsigned int *cwrite, unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunbr_count(cwrite, nb / 10);
		ft_putunbr_count(cwrite, nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		*cwrite = *cwrite + 1;
	}
}
