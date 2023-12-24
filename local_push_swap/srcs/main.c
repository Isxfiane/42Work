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

	int	min;
	int max;

	if (argc == 1)
		return (1);
	lista = NULL;
	lista = ft_fill_numb(lista, argc, argv);
	if (lista == NULL)
	{
		printf("Error\n");
		return (1);
	}
	ft_printf("A :");
	ft_print_list(lista);
	ft_mainalgo(lista);
	ft_printf("A :");
	ft_print_list(lista);
	return (0);
}
