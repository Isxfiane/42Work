
1. [x] Ameliorer la reception avec sigaction

*La premiere reception est la taille du la string*
2. [ ] Recuperer cette taille et la passer dans `atoi base`
3. [x] Creer le buffer de recuperation
3. [x] Passer un parametre a `n = 1` pour changer de call de fonction
4. [ ] Recuperer et mettre dans le buffer les chars
5. [ ] ft_printf du buffer


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