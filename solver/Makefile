##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	gcc

PTH	=	src/

BF	=	basic_functions/

SM	=	solve_maze/

SRC	=	$(PTH)main.c	\
		$(PTH)$(BF)get_file_content.c	\
		$(PTH)$(BF)print_arr.c 	\
		$(PTH)$(BF)string_to_tab.c	\
		$(PTH)$(BF)free_2d_array.c 	\
		$(PTH)$(BF)tab_to_int_tab.c 	\
		$(PTH)$(SM)map_solver.c 	\
		$(PTH)$(SM)find_wayout.c 	\
		$(PTH)$(SM)check_around.c	\
		$(PTH)$(SM)back_track.c 	\
		$(PTH)$(SM)how_many.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-iquote ./include/ -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
