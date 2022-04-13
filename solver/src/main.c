/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "my_solve.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (map_solver(av[1]) != 0)
        return 84;
    return 0;
}
