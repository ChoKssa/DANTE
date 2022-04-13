/*
** EPITECH PROJECT, 2022
** generate_imperfect_map.c
** File description:
** function that will generate imperfect map
*/

#include "maze.h"
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

maze fill_path(maze maze, int *i, int *j, int *random)
{
    if (maze.map[*i][*j] != '*') {
        *random = rand();
        if (*random % 2 == 0)
            maze.map[*i][*j] = '*';
        else
            maze.map[*i][*j] = 'X';
    }
    return maze;
}

maze assign_obstacles(maze maze)
{
    int i = 0;
    int random_nbr = 0;

    srand(time(NULL));
    while (i < maze.y_end) {
        for (int j = 0; j < maze.x_end; j++) {
            maze = fill_path(maze, &i, &j, &random_nbr);
        }
        i++;
    }
    return maze;
}

int imperfect_maze(char **av)
{
    maze maze = fill_infos(av);
    int random_nbr = 0;

    srand(time(NULL));
    while (maze.map[maze.y_end - 1][maze.x_end - 1] != '*') {
        maze.map[maze.pos_y][maze.pos_x] = '*';
        random_nbr = rand() % 15;
        if (random_nbr == 0 && maze.pos_y >= 0 && maze.pos_y < maze.y_end - 1)
            maze.pos_y += 1;
        if (random_nbr == 1 && maze.pos_x >= 0 && maze.pos_x < maze.x_end - 1)
            maze.pos_x += 1;
        if (random_nbr == 3 && maze.pos_y >= 1 && maze.pos_y < maze.y_end - 1)
            maze.pos_y -= 1;
    }
    maze = assign_obstacles(maze);
    my_print_2d_array(maze.map, '\n');
    my_free_2d_array(maze.map);
    return 0;
}

int check_args_imperfect(char *x ,char *y)
{
    for (int i = 0; x[i]; i++) {
        if (x[i] < '0' || x[i] > '9')
            return -1;
    }
    for (int i = 0; y[i]; i++)
        if (y[i] < '0' || y[i] > '9')
            return -1;
    return 0;
}

int generate_imperfect_map(char **av)
{
    if (check_args_imperfect(av[1], av[2]) != 0) {
        write(2, "ERROR, please enter digits as coordinates for x & y\n", 52);
        return 84;
    }
    return imperfect_maze(av);
}
