/*
** EPITECH PROJECT, 2022
** solve.h
** File description:
** solve header
*/

#ifndef _MY_SOLVE_H
    #define _MY_SOLVE_H

typedef struct {
    char **map;
    int pos_x;
    int pos_y;
    int x_end;
    int y_end;
    int crsmt;
} maze;

char *get_file_content(char const *filepath);
char **string_to_tab(char *tab, int rows, int cols);
void my_free_2d_array(char **array);
int **tab_to_int_tab(char **array, int rows, int cols);
void print_arr(char **arr);

int map_solver(char *filepath);
int how_many_rows(char const *str);
int how_many_cols(char const *str);
int find_wayout(maze *solv);
int which_direction(maze *solv);
int is_croisements(maze *solv);
void back_track(maze *s);
void seek_path(maze *s, int path, int c);

#endif /*_MY_SOLVE_H*/
