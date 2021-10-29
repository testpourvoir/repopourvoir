##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## root Makefile
##

CC		=	gcc

NAME		=	eval_expr

SRC		=	summands.c			\
			factors.c			\
			eval_expr.c			\
			error_handling.c	\
			error_handling_2.c	\
			my_int_to_str.c		\
			make_operate.c

TESTS_NAME	=	tests/test

FLAGS		=	-I./include -L./lib -lmy

all		:
			make -C lib/my
			make comp

comp		:
			$(CC) -o $(NAME) $(SRC) $(FLAGS)

tests		: all
			make -C tests
			./$(TESTS_NAME)
			gcovr -e tests
			gcovr -e tests -bu

clean		:	make clean -C lib/my

cclean		:
			rm $(NAME)

fclean		:
			make fclean -C lib/my
			rm -f $(NAME)

tclean		:
			make fclean -C tests

re		:	fclean all

full		:
			make full -C lib/my

.PHONY		:	all tests fclean
