/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:19:22 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/08 13:39:16 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

long int	ft_atol(const char *nptr)
{
	long int	nb;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-' )
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (21474836488);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + (nptr[i++] - '0');
	if (ft_isdigit(nptr[i]) == 0 && nptr[i] != '\0')
		return (21474836488);
	return (nb * sign);
}

t_list	*ft_fill_numb(t_list *li, int argc, char **argv)
{
	int			i;
	long int	nb;

	i = 1;
	while (i != argc)
	{
		nb = ft_atol(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			ft_lst_clear(li);
			return (NULL);
		}
		if (ft_listchr(li, nb) != 0)
		{
			ft_lst_clear(li);
			return (NULL);
		}
		ft_lstadd_back(&li, (int)nb);
		i++;
	}
	return (li);
}
