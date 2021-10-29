##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile my libmy.
##

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c		\
		my_getnbr.c			\
		my_isneg.c			\
		my_is_prime.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_showmem.c			\
		my_showstr.c			\
		my_sort_int_array.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_strupcase.c			\
		my_swap.c			\
		my_strcapitalize.c			\
		my_max.c			\
		my_min.c			\
		my_abs.c			\
		my_str_isan.c			\
		my_str_without_space.c			\
		my_strdup.c			\
		my_str_without_char_array.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

HEADERS		=	my.h			\
			error_cases.h

all:		$(NAME)
		mv $(NAME) ../
		mkdir -p ../../include
		cp $(HEADERS) ../../include/

$(NAME):	$(OBJ)
		ar rc $(NAME) *.o

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -rf ../../include
		rm -f ../$(NAME)

re:		fclean	all

full:		fclean
		rm -rf ../../include
		rm ../libmy.a
