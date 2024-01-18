/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:21:18 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/18 16:52:09 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"



void handleUSR1(int signo)
{
	if (signo == SIGUSR1)
		write(1, "Recu.\n", 6);
	else if (signo == SIGUSR2)
		write(1, "White Flag.\n", 12);
}

int main() {
	int x;
	struct sigaction sa;

	x = getpid();
	ft_printf("\t%d\n", x);
	sa.sa_handler = &handleUSR1;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("All good ઑ !\n");
	while (1) {
		(void)x;
	}
	return 0;
}

/*
int	main(void)
{
	int x;
	int sig;
	sigset_t set;



	// Initialiser l'ensemble de signaux
	sigemptyset(&set);
	sigaddset(&set, SIGILL); // Ajouter le signal SIGINT à l'ensemble
	while (1)
	{
		printf("\nAttente du signal...\n");
		// Attendre la réception du signal SIGINT
		if (sigwait(&set, &sig) != 0)
		{
			perror("Erreur lors de l'attente du signal");
			exit(EXIT_FAILURE);
		}
		printf("Signal SIGINT reçu. Numéro du signal : %d\n", sig);
	}
	return 0;
}
*/