/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:53:53 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/26 11:55:20 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putnbr_hexa(unsigned long long n, int i, int *cwrite)
{
	unsigned int	k;
	char			*base;

	if (i == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	k = ft_strlen(base);
	if (n >= k)
	{
		ft_putnbr_hexa(n / k, i, cwrite);
		ft_putnbr_hexa(n % k, i, cwrite);
	}
	else
	{
		if (ft_putchar_fd(base[n], 1) == -1)
			return (-1);
		*cwrite = *cwrite + 1;
	}
	return (0);
}
