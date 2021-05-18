##
## EPITECH PROJECT, 2020
## B-CPE-100-NAN-1-1-cpoolday10-alexandre.laborde
## File description:
## Makefile
##

TSRC	=	tests/Test_matchstick.c		\
			src/error.c					\
			src/game_status.c			\
			src/game.c					\
			src/ia_turn.c				\
			src/input_error.c			\
			src/map_generator.c			\
			src/matchstick.c			\
			src/play_move.c				\
			src/player_turn.c			\


TOBJ	=	$(TSRC: .c=.o)

NAME	= 	tests_matchstick			\

SRC		=	src/error.c					\
			src/game_status.c			\
			src/game.c					\
			src/ia_turn.c				\
			src/input_error.c			\
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
			rm -f *.gcno
			rm -f *.gcda

fclean: 	clean
			rm -f $(NAME)
			rm -f $(TNAME)
			make fclean -C lib/my

re:			fclean all

test_run:	$(TOBJ)
			make -C lib/my
			gcc -o tests_matchstick $(TOBJ) -Llib -lmy -Iinclude -lcriterion --coverage
			./tests_matchstick
			gcovr --exclude tests
			gcovr --exclude tests --branches