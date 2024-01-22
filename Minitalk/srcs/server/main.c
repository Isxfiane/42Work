/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:21:18 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/22 16:14:15 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int signal_result;

void handleUSR1(int signo)
{
	if (signo == SIGUSR1)
		signal_result = 0;
	else if (signo == SIGUSR2)
		signal_result = 1;
	else
		signal_result = -1;
}

int	fill(int x, char *buffer, char *result)
{
	int n;

	n = 0;
	while (1)
	{
		if (signal_result == 1 || signal_result == 0)
		{
			buffer[x] = one_or_zero(signal_result);
			buffer[x + 1] = '\0';
			signal_result = 2;
			if (x > 7 && ft_strstr(buffer, "100000000") != -1)
			{
				result = copyandclear(buffer, &n, result);
				x = -1;
			}
		x++;
		}
	}
}

int main()
{
	int x;
	struct sigaction sa;
	char	*buffer;
	char	*result;

	x = getpid();
	ft_printf("\t%d\n", x);
	buffer = malloc(sizeof(char) * 16);
	result = NULL;
	if (!buffer)
		return (1);
	x = 0;
	signal_result = 2;
	sa.sa_handler = &handleUSR1;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	fill(x, buffer, result);
	return 0;
}
