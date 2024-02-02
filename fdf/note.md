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
3. [ ] Parsing de la map.
2. [ ] Trouver la formule pour afficher sur un plan iso | calculer avec `x, y, z` `x', y'`.
4. [ ] Assemblage et debug.

> *Seulement les points principaux doivent etre convertie, pas tout un segement.*