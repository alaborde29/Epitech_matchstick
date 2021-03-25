##
## EPITECH PROJECT, 2020
## B-CPE-100-NAN-1-1-cpoolday10-alexandre.laborde
## File description:
## Makefile
##

SRC		=	src/main.c				\
			src/matchstick.c		\
			src/error.c				\
			src/map_generator.c		\

OBJ		=	$(SRC: .c=.o)

NAME	= 	matchstick

all: 		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -g -o $(NAME) $(OBJ) -Llib -lmy -Iinclude

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)
		make fclean -C lib/my

re:		fclean all