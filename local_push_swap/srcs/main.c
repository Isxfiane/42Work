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
	int	min;
	int max;

	if (argc == 1)
		return (1);
	lista = NULL;
	listb = NULL;
	lista = ft_fill_numb(lista, argc, argv);
	if (lista == NULL)
	{
		printf("Error\n");
		return (1);
	}
	ft_printf("A :");
	ft_print_list(lista);
	max = ft_findmax(lista);
	min = ft_findmin(lista);
	ft_printf("[MAX : %d] [%d]\n",max, ft_listchr(lista, max));
	ft_printf("[MIN : %d] [%d]\n",min, ft_listchr(lista, min) );

	return (0);
}
