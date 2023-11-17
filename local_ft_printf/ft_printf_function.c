/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:30 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/17 15:02:48 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"


void	string_function(unsigned int *cwrite, va_list args)
{
	char	*cpy;

	cpy = ft_strdup(va_arg(args, char*));
	ft_putstr_fd(cpy, 1);
	*cwrite = (*cwrite + ft_strlen(cpy));
	free(cpy);
}

static int get_size(int nb)
{
	int	i;
	unsigned int abs;

	abs = nb;
	i = 1;
	while (abs > 9)
	{
		abs = abs / 10;	
		i++;
	}
	return (i);
}

void	ft_putnbr_count(unsigned int *cwrite, va_list args)
{
	int	len;
	int	nb;
	
	nb = va_arg(args, int);
	len = get_size(nb);
	ft_putnbr_fd(nb, 1);
	if (nb > 0)
		*cwrite = len;
	else 
		*cwrite = len + 1 ;
}

void    ft_putnbr_base(int nbr, char *base, unsigned int *cwrite)
{
	long long	r_nbr;
	int			k;
	r_nbr = nbr;
	k = ft_strlen(base);
	if (r_nbr < 0)
	{
		ft_putchar_fd('-', 1);
		r_nbr = r_nbr * (-1);
		*cwrite = *cwrite + 1;
	}
	if (r_nbr >= k)
	{
		ft_putnbr_base(r_nbr / k, base, cwrite);
		ft_putnbr_base(r_nbr % k, base, cwrite);
	}
	else
	{
		ft_putchar_fd(base[r_nbr], 1);
		*cwrite = *cwrite + 1;
	}
}

void	ft_ftoa(double nb)
{
	// 


	
}
