##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	gcc

PTH	=	src/

FCT	=	basic_functions/

PERFECT	=	perfect/

IMPERFECT	=	imperfect/

SRC	=	$(PTH)main.c	\
		$(PTH)$(FCT)mem_alloc_2d_array.c	\
		$(PTH)$(FCT)my_free_2d_array.c	\
		$(PTH)$(FCT)my_print_2d_array.c	\
		$(PTH)$(PERFECT)initialize.c	\
		$(PTH)$(IMPERFECT)generate_imperfect_map.c	\
		$(PTH)$(PERFECT)generate_perfect_map.c	\
		$(PTH)$(PERFECT)generator.c	\
		$(PTH)$(PERFECT)choose_direction.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

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
