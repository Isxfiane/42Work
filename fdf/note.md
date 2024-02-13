# *NOTE*

*__Pour compiler en attendant le `Makefile` :__*
```
cc test.c  minilibx-linux/libmlx_Linux.a -Lminilibx-linux -lmlx -lXext -lX11 && ./a.out
```

*__Doc de note `MiniLibX` :__*
>[*Lien vers Github.*](https://harm-smits.github.io/42docs/libs/minilibx/loops.html)


<br>

    Toujours passer par une `struct` contenant toutes les informations lier au pointeur sur mlx.

# *To do list*

1. [x] Afficher une ligne correctemnt `draw_to`.
3. [x] Parsing de la map.
4. [x] Assemblage et debug.
2. [x] Trouver la formule pour afficher sur un plan iso | calculer avec `x, y, z` `x', y'`.
3. [x] Securiter lors du print a faire
3. [ ] Faire un scale inteligent

> *Seulement les points principaux doivent etre convertie, pas tout un segement.*
>
>

```c
t_map *parsing_and_coord()
{
/*
     * Parsing.c
     * Treat_Value.c
     * Creat_cord.c
*/
}
```
```c
t_mlx *init_and_hook()
{
/*
    * init / hook
 */
}
```
```c
t_img *create_image()
{
/*
    * create image (a faire)
*/
}
```
```c
int main(int argc, char **argv)
{
/*
    ...
    
    * loop
    * free
*/
}

```


