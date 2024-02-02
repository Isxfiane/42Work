/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:57:22 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/26 12:06:51 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	print_address(unsigned long long add, int *cwrite)
{
	if (add == 0)
	{
		if (string_function(cwrite, "(nil)") == -1)
			return (-1);
		return (0);
	}
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	*cwrite = *cwrite + 2;
	if (ft_putnbr_hexa(add, 0, cwrite) == -1)
		return (-1);
	return (0);
}

int	ft_putunbr_count(int *cwrite, unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunbr_count(cwrite, nb / 10);
		ft_putunbr_count(cwrite, nb % 10);
	}
	else
	{
		if (ft_putchar_fd(nb + '0', 1) == -1)
			return (-1);
		*cwrite = *cwrite + 1;
	}
	return (0);
}

int	ft_putnbr_count(int *cwrite, int nb)
{
	int	len;

	len = get_size(nb);
	if (ft_putnbr_fd(nb, 1) == -1)
		return (-1);
	if (nb >= 0)
		*cwrite = *cwrite + len;
	else
		*cwrite = *cwrite + len + 1 ;
	return (0);
}
