/*
** EPITECH PROJECT, 2022
** back_track.c
** File description:
** if the player is stuck in a dead end -> back track
*/

#include "my_solve.h"
#include <stdio.h>

int escape_deadend(maze *s)
{
    int i = s->pos_y;
    int j = s->pos_x;

    if (i + 1 <= s->x_end && s->map[i + 1][j] == 'o') {
        s->map[i][j] = 's';
        return 0;
    }
    if (j + 1 <= s->y_end && s->map[i][j + 1] == 'o') {
        s->map[i][j] = 's';
        return 1;
    }
    if (j > 0 && s->map[i][j - 1] == 'o') {
        s->map[i][j] = 's';
        return 2;
    }
    if (i > 0 && s->map[i - 1][j] == 'o') {
        s->map[i][j] = 's';
        return 3;
    }
    return -1;
}

int reach_croismt(maze *s)
{
    int i = s->pos_y;
    int j = s->pos_x;

    if (i + 1 <= s->x_end && s->map[i + 1][j] == 'v') {
        s->map[i][j] = 's';
        return 0;
    }
    if (j + 1 <= s->y_end && s->map[i][j + 1] == 'v') {
        s->map[i][j] = 's';
        return 1;
    }
    if (j > 0 && s->map[i][j - 1] == 'v') {
        s->map[i][j] = 's';
        return 2;
    }
    if (i > 0 && s->map[i - 1][j] == 'v') {
        s->map[i][j] = 's';
        return 3;
    }
    return -1;
}

void back_track(maze *s)
{
    int direction = -1;

    while (s->map[s->pos_y][s->pos_x] != 'v') {
        direction = escape_deadend(s);
        if (direction == -1)
            direction = reach_croismt(s);
        seek_path(s, direction, 0);
    }
}
