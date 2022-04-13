/*
** EPITECH PROJECT, 2022
** find_wayout.c
** File description:
** find a way out of the maze
*/

#include "my_solve.h"
#include <stdio.h>

static int is_solve(maze *solv)
{
    int i = solv->x_end;
    int j = solv->y_end;

    if (solv->map[i - 1][j] == 'o')
        return 1;
    else if (solv->map[i][j - 1] == 'o')
        return 1;
    else
        return 0;
}

void seek_path(maze *s, int path, int c)
{
    if (c > 1)
        s->map[s->pos_y][s->pos_x] = 'v';
    if (path == 0)
        s->pos_y += 1;
    if (path == 1)
        s->pos_x += 1;
    if (path == 2)
        s->pos_x -= 1;
    if (path == 3)
        s->pos_y -= 1;

}

int find_wayout(maze *s)
{
    int path = 0;
    int c = 0;

    while (is_solve(s) == 0) {
        s->map[s->pos_y][s->pos_x] = 'o';
        c = is_croisements(s);
        path = which_direction(s);
        seek_path(s, path, c);
        if (c == 0)
            back_track(s);
    }
    s->map[s->x_end][s->y_end] = 'o';
    return 0;
}
