/*
** EPITECH PROJECT, 2022
** maze.h
** File description:
** maze
*/

#ifndef _MAZE_H
    #define _MAZE_H
    #define BOTH_DIRECTION is_possible_direction(maze->map, *i, *j) == 0
    #define BOTH_PAIR maze->x_end % 2 == 0 && maze->y_end % 2 == 0

typedef struct {
    char **map;
    int pos_x;
    int pos_y;
    int x_end;
    int y_end;
    int line;
} maze;

int **alloc_int_2d_array(int nb_rows, int nb_cols);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void free_int_2d_array(int **values, int rows);
void my_free_2d_array(char **array);
void print_int_2d_array(int **values, int rows, int cols);
void my_print_2d_array(char **array, char lim);

int generate_imperfect_map(char **av);
int generate_perfect_map(char **av);

maze fill_infos(char **av);
void initialize_map(maze maze);

void generator(maze *maze);

int which_direction_is_possible(char **map, int i, int j);
int is_possible_direction(char **map, int i, int j);

#endif /*_MAZE_H*/
