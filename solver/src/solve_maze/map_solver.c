/*
** EPITECH PROJECT, 2022
** map_solver.c
** File description:
** get the file in parameter and transform it in a maze
*/

#include "my_solve.h"
#include <stdio.h>
#include <stdlib.h>

static maze set_solv(char *file, int rows, int cols)
{
    maze var;

    rows = how_many_rows(file);
    cols = how_many_cols(file);
    var.x_end = rows;
    var.y_end = cols - 1;
    var.map = string_to_tab(file, rows, cols);

    return var;
}

static char check_char(char c)
{
    if (c == 'o' || c == 'v')
        return 'o';
    if (c == 's')
        return '*';
    return c;
}

static void draw_route(maze *s)
{
    for (int i = 0; s->map[i]; i++) {
        for (int j = 0; s->map[i][j]; j++)
            s->map[i][j] = check_char(s->map[i][j]);
    }
}

int map_solver(char *filepath)
{
    maze solv;
    char *file = get_file_content(filepath);
    int rows = 0;
    int cols = 0;

    if (file == NULL)
        return 84;
    solv = set_solv(file, rows, cols);
    find_wayout(&solv);
    draw_route(&solv);
    print_arr(solv.map);
    free(file);
    return 0;
}
