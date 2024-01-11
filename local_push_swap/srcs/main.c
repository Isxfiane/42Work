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
#include "test.h"

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
//	ft_print_list(lista);
	ft_lst_clear(lista);
	ft_lst_clear(listb);
	return (0);
}

/*
#include "string.h"
int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;
	char	str[100] = "ABC";

	if (argc == 1)
		return (1);
	lista = NULL;
	listb = NULL;
	lista = ft_fill_numb(lista, argc, argv);
	ft_printf("A :");
	ft_print_list(lista);
	ft_printf("B :");
	ft_print_list(listb);
	ft_printf("\n");
	while (strcmp(str, "stop") != 0)
	{
		scanf("%s", str);
		if (strcmp(str, "sa") == 0)
			ft_lst_swap(lista, "");
		else if (strcmp(str, "sb") == 0)
			ft_lst_swap(listb, "");
		else if (strcmp(str, "pb") == 0)
			ft_lst_push(&lista, &listb, "");
		else if (strcmp(str, "pa") == 0)
			ft_lst_push(&listb, &lista,"");
		else if (strcmp(str, "ra") == 0)
			ft_lst_rot(&lista, "");
		else if (strcmp(str, "rb") == 0)
			ft_lst_rot(&listb,"");
		else if (strcmp(str, "rra") == 0)
			ft_lst_rerot(&lista,"");
		else if (strcmp(str, "rrb") == 0)
			ft_lst_rerot(&listb,"");
		else
			ft_printf("Invalid\n");
		ft_printf("A :");
		ft_print_list(lista);
		ft_printf("B :");
		ft_print_list(listb);
		ft_printf("\n");
	}
	ft_lst_clear(lista);
	ft_lst_clear(listb);
	return 0;
}
*/