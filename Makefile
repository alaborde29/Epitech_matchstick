##
## EPITECH PROJECT, 2020
## B-CPE-100-NAN-1-1-cpoolday10-alexandre.laborde
## File description:
## Makefile
##

SRC		=	src/error.c					\
			src/game_status.c			\
			src/game.c					\
			src/ia_turn.c				\
			src/main.c					\
			src/map_generator.c			\
			src/matchstick.c			\
			src/play_move.c				\
			src/player_turn.c			\

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