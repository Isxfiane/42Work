# Main
Dans notre main on passe de `int main(int argc, char **argv)` a `int main(int argc, char **argv, char **envp)`. <br>
le `envp` ajouter est en `char **`, donc un tableau de string qui est terminer par `NULL`, ainsi on peut l'afficher de la maniere suivante
```c
int main(int argc, char **argv, char **envp)
{
	int     i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

```
Tout ce qui est envoyer est consultable dans un terminale, hors progame avec
```bash
env
```
Certains elements, tels les `Variables d'environement` sont locale a un terminal, donc tout faire avec le meme.<br>
D'ailleurs `env` contient le resultat de la commande `pwd`.
<br>
Les `PATH` nous sont nescessaire pour lancer des commandes il faut donc pouvoir les recuperer et les exploiter, voici une fonction qui les recuprer en tableau de string (char **).

```c
char	**get_cmdpaths(char **const env)
{        
	char *raw_paths;
	char **paths;
	int    i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	raw_paths = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	if (!raw_paths)
		return (0);
	paths = ft_split(raw_paths, ':');
	if (!paths)
		return (NULL);
	free(raw_paths);
	return (paths);
}
```

# Variable d'environnement
Des qu'un `$` est croiser, cela signifie qu'on va avoir le nom d'une __Variable d'environement__.
- *Dans ce cas on peut recuprer le nom de la variable en **lisant** la suite du nom puis avec la fonction `getenv(char * name)`.*
- *Ensuite il faut donc remplace dans la chaine princpal le `$NAME` par ce qu'il en est.*
```c
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
	char *var = getenv("PATH"); // Ducoup il faut parser le nom des que `$` est trouver
	printf("la valeur de PATH est %s\n", var ); // Ici on print mais faudrat remplacer
}
```
- Un ARGS peut contenir un commande et cela doit etre traiter.
<br>

# ReadLine
La fonction `readline(prompt)` attend qu'une ligne soit envoyer dans le terminal est la met en string **sans aucune modification**. <br>
Elle inclue d'autre fonction comme `add_history(char *add)`, `rl_clear_history,` `rl_replace_line` ou d'autre encore.<br>
***ATTENTION LA FONCTION LEAK EN ELLE MEME***
```c
int main(int argc, char **argv, char **envp)
{
	while (1)
	{
		zebi = readline("\e[3;35mMinishell > \e[0m"); // prompt sera afficher a chaque fois en newline
		printf("%s\n", zebi); // on affiche la ligne recup
		add_history(zebi); // ajout a un historique avec `up`.
		free(zebi); // free
	}
	rl_clear_history(); // clear_history
}
```
<br>

# Quoting & Expansion | L'avant traitement
En bash, sur une simple ligne de commande beaucoup d'element doivent etre etendue, notre amis bash le fait avec des ordres de prioriter et agis en fonction du type de `quote` (Quoting), une fois fait, il traite le commande. pour les exemple, voici `ARGS`.

>  `Quoting `| Premier arriver, premier servis. (Meme si l'autre est present, blc)
- Single Quotes (`''`) (Texte `brute` prit en compte)
- Double Quotes (`""`) (Ecoute que `$` en meta-char)
> `Expansion` | Ordre a suivre.
- Locale-Specific Translation (`Variable d'environnement`)
- Retirer les quotes principales

Exemple :

Initialisation de `ARGS`
```bash
ARGS="YOOO"
```

*Single Quotes :*
```bash
echo -n '$ARGS'
```
Affiche `$ARGS`.

*Double Quotes :*
```bash
echo -n "$ARGS"
```
Affiche `YOOO`. *Autre test :*
```bash
TEST="zebi"
ARGS="'$TEST'"
echo -n "$ARGS"
```
Affiche `'zebi'`.

[Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) pourrait aider a comprendre plus.

<br>

# Notre (ma) mission | Traitement
Parser tout les elements pour les mettres dans une structure prete a executer la commande demander, la structure sera constuit de cette maniere pour faciliter le travail du mate
```c
typedef struct s_info
{
	char	**path; // Ton tableau avec tout les path
	char	*cmd // comme ya que une fonction qui en prend, je met juste une string, si y'a pas de flags alors = NULL; (cmd + flags)
	char	**args // les arguments avec des `\n` s'il faut retour ligne ou autre
	char	*file;	// == NULL | fd = 1 sinon 
	int		fd; // fd == -1 
}               t_info;
```
Attention il faut appliquer l'odre suivant
- Realiser les expand pour avoir une string complete
- Et seulement ensuite traiter cette string.
<br>

# Plan du code 4-4-2

- [ ] Stack des `PATH`
	- `char	**get_cmdpaths(char **const env)`
- [ ] Pre-Check
	- si `"[]{}()\\;&^%#@*,:"` | si `quotes non fini` > **Refus de la commande**
> **Le reste des etapes sont a realiser a petit a petit sur TOUTE la string** (Donc y'a moyen que se soit fait plusieurs fois)<br> 
Exemple : `blahblah'$ARGS'bouhbouh"$ARGS"` | `"blahblah'$ARGS'bouhbouh""$ARGS"` > plusieurs passage vu que plusieur Quoting
- [ ] Retrait de la commande & des flags | stack dans la struct
- [ ] Retrait des pipe && redirection | traitement plus tard
- [ ] Quoting
	- mod_1 : `""` | Expension a faire
	- mod_2 : `''` | Expension a skip
- [ ] Expansion
	- Recherche des replaces && replace
- [ ] Retrait des quotes *(A reflechir)*
- [ ] Rangement dans `char **` *(A reflechir)*
	- Chaque fois qu'on a traiter une portions 
- [ ] Envoie de infos
- [ ] Si `|` ou `>` agir en fonction
	- `|` Recup le result de la premiere cmd et devient args de la deuxieme, dans ce cas `fd == -1` et `file == NULL`.
	- `>` Set `fd == -1` && `file == (nom du fichier)`
	- sinon `fd == 1` && `file == NULL``

# Note pure
- Golden garbage (List chainee qui contient l'addresse de tout les element malloc, comme sa par de galere en cas de free_all)
- Ne pas oublier qu'une commande peut fail, mais pas pour autant close le programe.
- **TOUJOURS** ce referer au terminal en **BASH** en cas de doute
- Blacklist : "[]{}()\\;&^%#@*,:"
- **TOUT** ce qui **N'EST PAS DEMANDER DANS LE SUJET** n'est **PAS** a faire.
- Beleck si pas de `""` et que plusieurs args, tej les whitespaces.
- `ARGS=string` = Variable d'envirnnoment temporaire | `export ARGS=string` = Variable d'environnement present dans `env`
- Imagine que quand y'a pas de quotes, les espaces font offic de double quotes 