/*
** EPITECH PROJECT, 2022
** map_solver.c
** File description:
** get the file in parameter and transform it in a maze
*/

#include <stdio.h>

void print_arr(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        printf("%s", arr[i]);
        if (arr[i + 1] != NULL)
            printf("\n");
    }
}
