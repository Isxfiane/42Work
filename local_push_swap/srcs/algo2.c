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
		if (content > max)
			ft_lst_rot(lb, "rb");
	}
	else
		safeplace(la, lb, content);
}

void	pushandrepush(t_list **la, t_list **lb)
{
	int len;
	int	j;
	int i;

	len = ft_listlen(*la);
	i = 0;
	j = 0;
	while (len != 0)
	{
		minialgo(la, lb);
		if (i == 10 || len == 1)
		{
			while (j != 10)
			{
				ft_lst_reverse(lb, ft_findmax((*lb)), "rb", "rrb");
				ft_lst_push(lb, la, "pa");
				ft_lst_rot(la, "ra");
				j++;
			}
			j = 0;
			i = 0;
		}
		len--;
		i++;
	}
}
void	sortbigaglo(t_list **la, t_list **lb)
{

	pushandrepush(la, lb); // Donc la j'ai plein de morceaux de 10


}