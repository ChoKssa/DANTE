/*
** EPITECH PROJECT, 2022
** string_to_tab.c
** File description:
** Function get a char* and return a char**
*/

#include <stdlib.h>
#include <stdio.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **mem_al = malloc(sizeof(char *) * nb_rows);
    int i = 0;

    while (i != nb_rows) {
        for (int j = 0; j != nb_cols; j++) {
            mem_al[i] = malloc(sizeof(char) * nb_cols);
        }
        i ++;
    }
    return mem_al;
}

char **my_strcpy_2d_arr(char **dest, char *src)
{
    int i = 0;
    int k = 0;
    int j = 0;

    while (src[k] != '\0') {
        j = 0;
        for (; src[k] != '\n' && src[k] != '\0'; j++, k++) {
            dest[i][j] = src[k];
        }
        dest[i][j] = '\0';
        k++;
        i++;
    }
    dest[i] = NULL;
    return dest;
}

char **string_to_tab(char *str, int rows, int cols)
{
    char **tab_2d = mem_alloc_2d_array(rows+1, cols);

    if (!tab_2d)
        return NULL;
    tab_2d = my_strcpy_2d_arr(tab_2d, str);
    return tab_2d;
}
