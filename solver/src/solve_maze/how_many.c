/*
** EPITECH PROJECT, 2022
** how_many.c
** File description:
** count cols & rows
*/

int how_many_rows(char const *str)
{
    int i = 0;
    int r = 0;

    while (str[i]) {
        if (str[i] == '\n')
            r += 1;
        i += 1;
    }
    return r;
}

int how_many_cols(char const *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i += 1;
    }
    return i;
}
