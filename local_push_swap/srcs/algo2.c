#include "test.h"

void	minialgo(t_list **la, t_list **lb)
{
	int	min;
	int	max;
	int	content;

	max = ft_findmax((*lb));
	min = ft_findmin((*lb));
	content = (*la)->content;
	if (content < min || content > max)
	{
		if (ft_isreverse((*lb)) == -1)
			ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
		ft_lst_push(la, lb, "pb");
//		if (content < max)
//			ft_lst_rot(lb, "rb"); // -2
	}
	else
		safeplace(la, lb, content);
}

void	pushandrepush(t_list **la, t_list **lb, int limit)
{
	int len;
	int	j;
	int i;

	len = ft_listlen(*la) + 1;
	i = 0;
	j = -1;
	while (len != 0)
	{
		if (i == limit)
		{
			ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
			while (++j != limit)
				ft_lst_push(lb, la, "pa");
			j = -1;
			while (++j != limit)
				ft_lst_rot(la, "ra");
			j = -1;
			i = 0;
		}
		minialgo(la, lb);
		len--;
		if (len == 0)
		{
			ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
			while (++j != limit)
				ft_lst_push(lb, la, "pa");
			j = -1;
			while (++j != limit)
				ft_lst_rot(la, "ra");
			j = -1;
			i = 0;
		}
		i++;
	}
}
void	sortbigaglo(t_list **la, t_list **lb, int len)
{
	if (len > 498)
	{
		pushandrepush(la, lb, 50);
		logicalpush(la, lb, 50);
	}
	else
	{
		pushandrepush(la, lb, 20);
		logicalpush(la, lb, 20);
	}
	ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
	logcical_replace(la, lb);
}