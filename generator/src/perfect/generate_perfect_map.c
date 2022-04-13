/*
** EPITECH PROJECT, 2022
** generate_imperfect_map.c
** File description:
** function that will generate perfect map
*/

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"

void create_finish_maze(maze *maze)
{
    int random = rand();

    if (BOTH_PAIR && random % 2 == 0) {
        maze->map[maze->y_end - 1][maze->x_end - 1] = '*';
        maze->map[maze->y_end - 2][maze->x_end - 1] = '*';
    } else if (BOTH_PAIR && random % 2 != 0) {
        maze->map[maze->y_end - 1][maze->x_end - 1] = '*';
        maze->map[maze->y_end - 1][maze->x_end - 2] = '*';
    }
    if (maze->x_end % 2 != 0 && maze->y_end % 2 == 0)
        maze->map[maze->y_end - 1][maze->x_end - 1] = '*';
}

int perfect_maze(char **av)
{
    maze maze = fill_infos(av);

    initialize_map(maze);
    generator(&maze);
    create_finish_maze(&maze);
    my_print_2d_array(maze.map, '\n');
    my_free_2d_array(maze.map);
    return 0;
}

int check_args_perfect(char *x ,char *y, char *perfect)
{
    for (int i = 0; x[i]; i++) {
        if (x[i] < '0' || x[i] > '9')
            return -1;
    }
    for (int i = 0; y[i]; i++) {
        if (y[i] < '0' || y[i] > '9')
            return -1;
    }
    if (strcmp(perfect, "perfect") != 0)
        return -1;
    return 0;
}

int generate_perfect_map(char **av)
{
    struct timeval t1;

    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    if (check_args_perfect(av[1], av[2], av[3]) == -1) {
        write(2, "Invalid argument, try with format: 'x y perfect'\n", 49);
        return 84;
    }
    return perfect_maze(av);
}
