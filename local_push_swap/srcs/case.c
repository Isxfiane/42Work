#include "test.h"

void	case_two(t_list *li, char c)
{
	if (ft_isorder(li) == -1)
	{
		ft_lst_swap(li);
		ft_printf("s%c\n", c);
	}
}
t_list 	*algoforthree(t_list *li, int min, int max, char c)
{
	if (min == 2 && max == 3) // Nice
		case_two(li, c);
	else if (max == 1 && min == 3) // reroot
	{
		case_two(li, c);
		li = ft_lst_rerot(li);
		ft_printf("rr%c\n", c);
	}
	else if (max == 1 && min == 2) // Nice
	{
		li = ft_lst_rot(li);
		ft_printf("r%c\n", c);
	}
	else if (min == 1 && max == 2) // Nice
	{
		case_two(li, c);
		li = ft_lst_rot(li);
		ft_printf("r%c\n", c);
	}
	else if (max == 2 && min == 3)
	{
		li = ft_lst_rerot(li);
		ft_printf("rr%c\n", c);
	}
	return (li);
}
t_list 	*case_three(t_list *li, char c)
{
	int min;
	int max;
	int inmin;
	int inmax;

	if (ft_isorder(li) == 0)
		return(li);
	max = ft_findmax(li);
	min = ft_findmin(li);
	inmin = ft_listchr(li, min);
	inmax = ft_listchr(li, max);
	li = algoforthree(li, inmin, inmax, c);
	return (li);
}

