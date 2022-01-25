 ##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task 01
##

SRC	=	./src/main_file.c	\
		./src/accessory/object_create.c	\
		./src/accessory/my_putstr.c	\
		./src/accessory/my_put_nbr.c	\
		./src/accessory/my_revstr.c	\
		./src/accessory/my_strlen.c	\
		./src/accessory/approx_check.c	\
		./src/accessory/my_strcmp.c	\
		./src/accessory/h_writer.c	\
		./src/accessory/waiter.c	\
		./src/accessory/menu_accessory.c	\
		./src/background/backg_funct.c	\
		./src/background/parallax_file.c	\
		./src/background/menus.c	\
		./src/background/score.c	\
		./src/background/pause.c	\
		./src/initializers/init_file.c	\
		./src/initializers/init_file2.c	\
		./src/sprite_ressources/sam_ressources.c	\
		./src/sprite_ressources/flea_ressources.c	\
		./src/sprite_ressources/entity_actions.c	\
		./src/running/mouse_funct.c	\
		./src/running/map_utils.c	\
		./src/running/run.c	\
		./src/running/starters.c	\
		./src/initializers/free.c

NAME 	=	my_runner

CPPFLAGS =	-I./include -g
CPPFLAGS += -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

TESTS_FLAGS = --coverage -lcriterion

all:
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) -g

clean:
	rm -rf ./sources/*.o

cover:
		mkdir -p criterion_result
		gcovr --exclude tests/ --html --html-details -o crit_result/cov.html
		gcovr --branches --exclude tests/

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)
	rm -rf vg*
	rm -rf .gdb*
	rm -rf .vscode

re:	fclean all

tests_run:
	rm -rf unit*
	gcc -o unit_tests $(SRC) $(TESTS_SRC) $(TESTS_FLAGS)
	./unit_tests
	gcovr

auteur:
	echo $(USER) > auteur

.PHONY:	all clean fclean re auteur
