/*
** EPITECH PROJECT, 2022
** initialize.c
** File description:
** function that initialize struct maze
*/

#include <stdlib.h>
#include "maze.h"

static void assign_characters(maze *maze, int *i, int *j, int *a)
{
    if (*a % 2 == 0 && maze->line % 2 == 0)
        maze->map[*i][*j] = '*';
    else
        maze->map[*i][*j] = 'X';
}

void initialize_map(maze maze)
{
    int i = 0;
    int alternate = 0;

    maze.line = 0;
    while (i < maze.y_end) {
        for (int j = 0; j < maze.x_end; j++, alternate++) {
            assign_characters(&maze, &i, &j, &alternate);
        }
        maze.map[i][maze.x_end] = '\0';
        maze.line++;
        if (maze.x_end % 2 != 0)
            alternate++;
        i++;
    }
    maze.map[maze.y_end + 1] = NULL;
}

maze fill_infos(char **av)
{
    maze maze;

    maze.pos_x = 0;
    maze.pos_y = 0;
    maze.x_end = atoi(av[1]);
    maze.y_end = atoi(av[2]);
    if (maze.x_end == 0 || maze.y_end == 0)
        exit(84);
    maze.map = mem_alloc_2d_array(maze.y_end + 1, maze.x_end + 1);
    if (maze.map == NULL)
        exit(84);
    return maze;
}
