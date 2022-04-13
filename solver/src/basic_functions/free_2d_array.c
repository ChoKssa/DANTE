/*
** EPITECH PROJECT, 2022
** my_free_2d_array.c
** File description:
** free a 2d array
*/

#include <stdlib.h>

void my_free_2d_array(char **array)
{
    int a = 0;

    while (array[a]) {
        free(array[a]);
        array[a] = NULL;
        a++;
    }
    free(array);
    array = NULL;
}
