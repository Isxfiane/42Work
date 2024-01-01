#include "test.h"

void	case_two(t_list *li, char *str)
{
	if (ft_isorder(li) == -1)
	{
		ft_lst_swap(li, str);
		ft_printf("%s\n", str);
	}
}
t_list	*algoforthree(t_list **li, int min, int max)
{
	if (min == 2 && max == 3)
		case_two(*li, "sa");
	else if (max == 1 && min == 3)
	{
		case_two(*li, "sa");
		ft_lst_rerot(li, "rra");
	}
	else if (max == 1 && min == 2)
		ft_lst_rot(li, "ra");
	else if (min == 1 && max == 2)
	{
		case_two(*li, "sa");
		ft_lst_rot(li, "ra");
	}
	else if (max == 2 && min == 3)
		ft_lst_rerot(li, "rra");
	return (*li);
}
void	case_three(t_list **li)
{
	int min;
	int max;
	int inmin;
	int inmax;

	if (ft_isorder(*li) == 0)
		return ;
	max = ft_findmax(*li);
	min = ft_findmin(*li);
	inmin = ft_listchr(*li, min);
	inmax = ft_listchr(*li, max);
	algoforthree(li, inmin, inmax);
}