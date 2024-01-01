#include "test.h"

void	safeplace(t_list **la, t_list **lb)
{
	printf("zebo");
}

void	logicalpush(t_list **la, t_list **lb)
{
	int	min;
	int	max;
	int content;

	ft_lst_push(la, lb, "pb");
	ft_lst_push(la, lb, "pb");
	while(ft_listlen((*la)) != 3)
	{
		max = ft_findmax((*lb));
		min = ft_findmin((*lb));
		content = (*la)->content;
		ft_lst_push(la, lb, "pb");
		if (content < min || content > max)
		{
			if (ft_isreverse((*lb))== -1)
				ft_lst_reverse(lb);
			ft_lst_push(la, lb, "pb");
			if (content > max)
				ft_lst_rot(lb, "rb");
		}
		else
			safeplace(la, lb);
	}
}

void 	ft_mainalgo(t_list **li, t_list **b)
{
	int len;

	len = ft_listlen(*li);
	if (len == 0 || len == 1)
		return;
	if (len == 2)
		case_two(*li, "sa");
	if (len == 3)
		case_three(li);
	if (len > 3)
		logicalpush(li, b);
}