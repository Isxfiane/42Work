/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:50:04 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/22 13:50:55 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

long int	ft_atol(const char *nptr)
{
	long int	nb;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i = i + 1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	check_args(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("I need a PID !\n");
		return (1);
	}
	else if (argc > 3)
	{
		ft_printf("Too much args for me\n");
		return (1);
	}
	if (argv[2] == NULL)
		return (1);
	else
		return (0);
}

void	send_bin(const char *str, long int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(1);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	long int	pid;
	int			i;
	char		*temp;

	if (check_args(argc, argv) == 1)
		return (1);
	pid = ft_atol(argv[1]);
	i = -1;
	if (pid <= 0 || pid > 4194304)
	{
		ft_printf("Invalid PID !\n");
		return (1);
	}
	temp = ft_itoa_base(ft_strlen(argv[2]), "01");
	send_bin(temp, pid);
	free(temp);
	send_bin("100000000", pid);
	while (argv[2][++i] != '\0')
	{
		temp = ft_itoa_base(argv[2][i], "01");
		send_bin(temp, pid);
		free(temp);
		send_bin("100000000", pid);
	}
	send_bin("0100000000", pid);
	return (0);
}
