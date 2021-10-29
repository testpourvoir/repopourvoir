##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Build unit test
##

TESTS_OBJ	=	test_summands.c			\
			test_factors.c			\
			test_my_int_to_str.c			\
			test_get_next_operator.c			\
			test_error_handling.c			\
			test_error_handling_2.c			\
			test_error_handling_3.c

TESTS_SRC	=	../summands.c \
				../factors.c \
				../my_int_to_str.c \
				../error_handling.c			\
				../error_handling_2.c

TESTS_NAME	=	test

CC		=	gcc

LDFLAGS		=	--coverage -lcriterion -I./../include -L./../lib -lmy

all		:	fclean
			$(CC) -o $(TESTS_NAME) $(TESTS_OBJ) $(TESTS_SRC) $(LDFLAGS)

fclean		:
			rm -f $(TESTS_NAME)
			rm -f *.gc*
			rm -f *~

.PHONY		:	all fclean
