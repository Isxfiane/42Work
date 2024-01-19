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


// Fonction clean
//Recup que la parti qui nous interresse
// envoie a la bonne fonction (Set len ou fill buff)


// Buffer de 16// Reception basique
// Une fois délimitateur trouver, on regarde si on est au bout
// On fini de remplir avec des 2
// Call de fonction pour clean

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

char one_or_zero(int a)
{
	if (a == 1)
		return ('1');
	else
		return ('0');
}

int main()
{
	int x;
	struct sigaction sa;
	char	*buffer;

	x = getpid();
	ft_printf("\t%d\n", x);
	buffer = malloc(sizeof(char) * 16);
	x = 0;
	signal_result = 2;
	sa.sa_handler = &handleUSR1;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (signal_result == 1 || signal_result == 0)
		{
			buffer[x] = one_or_zero(signal_result);
			signal_result = 2;
			printf("%s\n", buffer);
			if (x > 8 && ft_strstr(buffer, "11111110") != -1)
				printf("Reaching.\n"); // Faut clear le buffer
			x++;
		}
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