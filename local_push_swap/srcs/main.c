/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:30:24 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/11 13:23:12 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;

	if (argc == 1)
		return (1);
	lista = NULL;
	listb = NULL;
	lista = ft_fill_numb(lista, argc, argv);
	if (lista == NULL)
	{
		ft_lst_clear(lista);
		ft_lst_clear(listb);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_mainalgo(&lista, &listb);
	ft_lst_clear(lista);
	ft_lst_clear(listb);
	return (0);
}
