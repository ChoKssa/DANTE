/*
** EPITECH PROJECT, 2022
** my_print_2d_array.c
** File description:
** print a 2d array
*/

#include <stdio.h>

static int len_2d_array(char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return i;
}

void my_print_2d_array(char **array, char lim)
{
    int i = 0;
    int len = len_2d_array(array);

    while (i < len - 1) {
        printf("%s", array[i]);
        if (i + 1 != len - 1)
            printf("%c", lim);
        i++;
    }
}
