/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "maze.h"

int main(int ac, char **av)
{
    if (ac == 3)
        return generate_imperfect_map(av);
    else if (ac == 4) {
        return generate_perfect_map(av);
    } else
        return 84;
}
