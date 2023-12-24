#include "test.h"

void	case_two(t_list *li)
{
	if (ft_isorder(li) == -1)
	{
		ft_lst_swap(li);
		ft_printf("SA\n");
	}
}