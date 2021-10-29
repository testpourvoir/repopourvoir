/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** A function that returns 84 with a error's case, else,
** that return 0.
*/

#include <my.h>
#include <error_cases.h>

const int EXIT_EMPTY = 84;
const int EXIT_NBR_PARAMS = 84;
const int EXIT_SYNTAX_ERROR = 84;
const int EXIT_NBR_OF_PARENTESIS = 84;

int is_char_is_that(char c, char *wanted);

int verif_in_parentesis(char *str);

int verif_nbr_of_parentesis(char *str)
{
    int nbr_of_parentesis = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            nbr_of_parentesis += 1;
        } else if (str[i] == ')') {
            nbr_of_parentesis -= 1;
        }
    }
    if (nbr_of_parentesis == 0) {
        return (verif_in_parentesis(str));
    } else {
        my_putstr(EXIT_NBR_OF_PARENTESIS_MSG);
        return (EXIT_NBR_OF_PARENTESIS);
    }
}

int verif_other_char(char *str, char *wanted)
{
    int is_here = 0;
    int actual = 0;

    for (int i = 0; str[i]; i++) {
        if (!is_char_is_that(str[i], wanted)) {
            my_putstr(EXIT_SYNTAX_ERROR_MSG);
            return (EXIT_SYNTAX_ERROR);
        }
    }
    return (verif_nbr_of_parentesis(str));
}

int verif_empty_msg(char *str)
{
    if (!str[0]) {
        my_putstr(EXIT_EMPTY_MSG);
        return (EXIT_EMPTY);
    } else {
        str = my_str_without_space(str);
        return (verif_other_char(str, "0123456789()+-*/%"));
    }
}

int verif_number_of_parameters(int ac, char **av)
{
    if (ac != 2) {
        my_putstr(EXIT_NBR_PARAMS_MSG);
        return (EXIT_NBR_PARAMS);
    } else {
        return (verif_empty_msg(av[1]));
    }
}

int error_handling(int ac , char **av)
{
    return (verif_number_of_parameters(ac, av));
}