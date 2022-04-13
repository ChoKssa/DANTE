##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SOLV	=	solver/

GEN	=	generator/

all:
	$(MAKE) -C $(SOLV)
	$(MAKE) -C $(GEN)

$(NAME):
	$(MAKE) -C $(SOLV)
	$(MAKE) -C $(GEN)

clean:
	$(MAKE) -C $(SOLV) clean
	$(MAKE) -C $(GEN) clean 

fclean: clean
	$(MAKE) -C $(SOLV) fclean
	$(MAKE) -C $(GEN) fclean

re: fclean all

.PHONY: all clean fclean re