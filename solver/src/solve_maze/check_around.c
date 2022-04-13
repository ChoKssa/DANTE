/*
** EPITECH PROJECT, 2022
** check_around.c
** File description:
** file to check around in the maze
*/

#include "my_solve.h"
#include <stdio.h>

int which_direction(maze *solv)
{
    int i = solv->pos_y;
    int j = solv->pos_x;

    if (i + 1 <= solv->x_end && solv->map[i + 1][j] == '*')
        return 0;
    if (j + 1 <= solv->y_end && solv->map[i][j + 1] == '*')
        return 1;
    if (j > 0 && solv->map[i][j - 1] == '*')
        return 2;
    if (i > 0 && solv->map[i - 1][j] == '*')
        return 3;
    return -1;
}

int is_croisements(maze *solv)
{
    int i = solv->pos_y;
    int j = solv->pos_x;
    int c = 0;

    if (i + 1 <= solv->x_end && solv->map[i + 1][j] == '*')
        c += 1;
    if (j + 1 <= solv->y_end && solv->map[i][j + 1] == '*')
        c += 1;
    if (j > 0 && solv->map[i][j - 1] == '*')
        c += 1;
    if (i > 0 && solv->map[i - 1][j] == '*')
        c += 1;
    return c;
}
