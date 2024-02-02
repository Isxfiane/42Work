/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:20:13 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/14 13:13:18 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size_nb(unsigned int n)
{
	unsigned int	count;

	count = 1;
	if (n == 10)
		return (2);
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*get_numb(char *n, unsigned int nbr, int sign, int len)
{
	int	save;

	save = len - 1;
	len = len - 2;
	while (len + 1 != sign)
	{
		n[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	n[save] = '\0';
	return (n);
}

char	*ft_itoa(int n)
{
	int				sign;
	unsigned int	nbr;
	int				len;
	char			*result;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nbr = n * -1;
	}
	else
		nbr = n;
	len = get_size_nb(nbr) + 1 + sign;
	result = (char *) malloc (sizeof(char) * len);
	if (result == NULL)
		return (NULL);
	if (sign == 1)
		result[0] = '-';
	result = get_numb(result, nbr, sign, len);
	return (result);
}
