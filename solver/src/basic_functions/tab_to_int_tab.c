/*
** EPITECH PROJECT, 2022
** tab_to_tab_int.c
** File description:
** transform an array into a int **
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

char is_wall(char c)
{
    switch (c) {
        case '*' :
            return '1';
        case 'X':
            return '0';
        default:
            return c;
    }
}

char **number_map(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        for (int  j = 0; arr[i][j] != '\0'; j++) {
            arr[i][j] = is_wall(arr[i][j]);
        }
    }
    return arr;
}

int **tab_to_int_tab(char **array, int rows, int cols)
{
    int **map = malloc(sizeof(int*) * rows);
    int i = 0;

    array = number_map(array);
    while (array[i]) {
        map[i] = malloc(sizeof(int)* cols);
        for (int j = 0; array[i][j] != '\0'; j++) {
            map[i][j] = array[i][j] - '0';
        }
        i += 1;
    }
    return map;
}
