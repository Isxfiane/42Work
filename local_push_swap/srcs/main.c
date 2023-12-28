/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:30:24 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/22 14:41:12 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	main(int argc, char **argv)
{
	t_list	*lista;
    t_list	*listb;

	if (argc == 1)
		return (1);
	lista = NULL;
	listb = NULL;
	lista =  ft_fill_numb(lista, argc, argv);
	if (lista == NULL)
	{
		ft_lst_clear(lista);
		ft_lst_clear(listb);
		printf("Error\n");
		return (1);
	}
	ft_printf("A :");
	ft_print_list(lista);
	ft_mainalgo(&lista, &listb);
	ft_printf("A :");
	ft_print_list(lista);
	ft_printf("B :");
	ft_print_list(listb);

	ft_lst_clear(lista);
	ft_lst_clear(listb);
	return (0);
}
