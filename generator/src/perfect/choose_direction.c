/*
** EPITECH PROJECT, 2022
** choose_direction.c
** File description:
** functions that will choose directions
*/

#include "maze.h"

int which_direction_is_possible(char **map, int i, int j)
{
    if (map[i][j + 2])
        return 1;
    else if (map[i + 2][j])
        return 2;
    else
        return -1;
}

int is_possible_direction(char **map, int i, int j)
{
    if (map[i][j + 2] && map[i + 2][j])
        return 0;
    else if (map[i][j + 2] || map[i + 2][j])
        return which_direction_is_possible(map, i, j);
    else
        return -1;
}
