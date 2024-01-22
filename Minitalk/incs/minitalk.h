#ifndef MINITALK_H
# define  MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include "stdio.h"

# include "ft_printf.h"

char	*ft_itoa_base(ssize_t nbr, char *base);
int		ft_strstr(const char *str, const char *tofind);
char	one_or_zero(int a);
int    ft_atoi_base(char *str, char *base);


#endif