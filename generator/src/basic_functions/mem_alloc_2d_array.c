/*
** EPITECH PROJECT, 2021
** mem_alloc_2d_array.c
** File description:
** mem_alloc_2d_array
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows , int nb_cols)
{
    int a = 0;
    char **str = malloc(sizeof(char *) * nb_rows + 1);

    while (a < nb_rows) {
        str[a] = malloc(sizeof(char) * nb_cols + 1);
        a++;
    }
    return str;
}
