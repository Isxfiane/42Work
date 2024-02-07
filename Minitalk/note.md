# To dot list.
1. [x] ***Client :*** Envoie du premier bits | Attente de signal.
2. [x] ***Server :*** Garde le PID | Traitement du bits | Renvoie de signal.
3. [x] ***Client :*** Envoie du prochains bits | Attente de signal.
>...
1. [x] ***Client :*** Envoie `00000000` comme delimitateur.
2. [x] ***Server :*** Set un compeur, lorsque `i = 8` c'est good.
> Traitement et mise du `char` dans `result`
1. [x] ***Client :*** Envoie le char `delimitateur` une fois fini.
2. [x] ***Server :*** Char `delimitateur` recu, lancement protocol de fin



```
int	main(int argc, char **argv)
{
long int x;

	(void)argc;
	x = ft_atol(argv[1]);
	if (ft_atol(argv[2]) == 1)
		kill(x, SIGUSR2);
	else if (ft_atol(argv[2]) == 9)
		kill(x, SIGILL);
	else
		kill(x, SIGUSR1);
	return (0);
}
```

