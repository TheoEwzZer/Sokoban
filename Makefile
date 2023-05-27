##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC	=	$(shell find src -type f -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

RM	=	rm -f

WARNING = -W -Wall -Wextra

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -g3 $(SRC) -o my_sokoban $(WARNING) -Llib/my -lmy -Iinclude -lncurses
	rm lib/libmy.a
	rm lib/my/libmy.a
	make clean

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
