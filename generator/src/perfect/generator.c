/*
** EPITECH PROJECT, 2022
** generator.c
** File description:
** generator functions
*/

#include <stdlib.h>
#include "maze.h"

static void break_walls(maze *maze, int which_direction, int *i, int *j)
{
    if (BOTH_DIRECTION && which_direction % 2 == 0)
        maze->map[*i + 1][*j] = '*';
    if (BOTH_DIRECTION && which_direction % 2 != 0)
        maze->map[*i][*j + 1] = '*';
    if (is_possible_direction(maze->map, *i, *j) == 1)
        maze->map[*i][*j + 1] = '*';
    if (is_possible_direction(maze->map, *i, *j) == 2)
        maze->map[*i + 1][*j] = '*';
}

static void pair_maze(maze *maze)
{
    int i = 0;
    int which_direction = 0;

    while (maze->map[i]) {
        for (int j = 0; maze->map[i][j]; j += 2) {
            which_direction = rand();
            break_walls(maze, which_direction, &i, &j);
        }
        i += 2;
    }
}

static void impair_maze(maze *maze)
{
    int i = 0;
    int which_direction = 0;

    while (i < maze->y_end - 1) {
        for (int j = 0; maze->map[i][j]; j += 2) {
            which_direction = rand();
            break_walls(maze, which_direction, &i, &j);
        }
        i += 2;
    }
    for (int k = 0; k < maze->x_end; k++)
        maze->map[maze->y_end - 1][k] = '*';
}

void generator(maze *maze)
{
    if (maze->y_end % 2 == 0)
        pair_maze(maze);
    else
        impair_maze(maze);
}
