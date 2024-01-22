/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:54:59 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/22 14:59:00 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	*get_size(ssize_t nbr, int len)
{
	char	*nb;

	if (nbr < 0)
	{
		nb = (char *)malloc((sizeof(char) * len) + 3);
		len++;
		nb[0] = '-';
	}
	else
		nb = (char *) malloc((sizeof(char) * len) + 2);
	return (nb);
}

int	ft_len_int(ssize_t nbr, ssize_t len_base)
{
	int	i;

	i = 0;
	if (nbr == 10)
		return (3);
	while (nbr != 0)
	{
		i++;
		nbr = nbr / len_base;
	}
	if (i == 0)
		return (0);
	return (i - 1);
}

char	*ft_itoa_base(ssize_t nbr, char *base)
{
	int			len;
	int			i;
	ssize_t		len_base;
	char		*nb;
	long long	abs_int;

	len_base = ft_strlen(base);
	i = -1;
	len = ft_len_int(nbr, len_base);
	nb = get_size(nbr, len);
	abs_int = nbr;
	if (nbr < 0)
		len++;
	if (nbr < 0)
		abs_int = abs_int * -1;
	if (abs_int == 0)
		nb[0] = base[0];
	while (abs_int != 0)
	{
		nb[len - ++i] = base[abs_int % len_base];
		abs_int = abs_int / len_base;
	}
	nb[len + 1] = '\0';
	return (nb);
}
