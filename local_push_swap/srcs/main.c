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


/*Mainn je suis l'algo
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
			ft_lst_swap(lista, "sa");
		else if (strcmp(str, "sb") == 0)
			ft_lst_swap(listb, "sb");
		else if (strcmp(str, "pb") == 0)
			ft_lst_push(&lista, &listb, "pb");
		else if (strcmp(str, "pa") == 0)
			ft_lst_push(&listb, &lista,"pa");
		else if (strcmp(str, "ra") == 0)
			ft_lst_rot(&lista, "ra");
		else if (strcmp(str, "rb") == 0)
			ft_lst_rot(&listb,"rb");
		else if (strcmp(str, "rra") == 0)
			ft_lst_rerot(&lista,"rra");
		else if (strcmp(str, "rrb") == 0)
			ft_lst_rerot(&listb,"rrb");
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