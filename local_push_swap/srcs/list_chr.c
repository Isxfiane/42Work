/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:38:25 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/16 11:06:10 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_lst_reverse(t_list **li, int x, char *rot, char *rerot)
{
	int	index;
	int	len;

	len = ft_listlen((*li)) + 1;
	index = ft_listchr((*li), x);
	index = index - 1;
	if (len / 2 < index + 1)
	{
		while (++index < len)
			ft_lst_rerot(li, rerot);
	}
	else
	{
		while (index > 0)
		{
			ft_lst_rot(li, rot);
			index--;
		}
	}
}

int	ft_listchr(t_list *li, long int x)
{
	int	i;

	if (isemptylt(li) == -1)
		return (0);
	i = 1;
	while (li != NULL)
	{
		if (li->content == x)
			return (i);
		i++;
		li = li->next;
	}
	return (0);
}
