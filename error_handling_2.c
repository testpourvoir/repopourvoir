/*
** EPITECH PROJECT, 2021
** error_handling_2.c
** File description:
** Complementary functions for error handling.
*/

#include <my.h>
#include <error_cases.h>

const int EXIT_NOTHING_IN_PARENTESIS = 84;
const int EXIT_TWO_ADJACENT_OPERATOR = 84;

const int SUCCESSFUL_PASS = 0;

int is_char_is_that(char c, char *wanted)
{
    for (int i = 0; wanted[i]; i++) {
        if (c == wanted[i]) {
            return (1);
        }
    }
    return (0);
}

int is_char_char_is_that_that(char *str, int i, char *wantone, char *wanttwo)
{
    if (is_char_is_that(str[i], wantone)) {
        if (is_char_is_that(str[i + 1], wanttwo)) {
            return (1);
        }
    }
    return (0);
}

int is_char_is_that_three(char *str, int i, char **wanteds)
{
    if (is_char_char_is_that_that(str, i, wanteds[0], wanteds[1])) {
        if (is_char_is_that(str[i + 2], wanteds[2])) {
            return (1);
        }
    }
    return (0);
}

int verif_two_adjacent_operator(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (is_char_char_is_that_that(str, i, "+-", "+-*/%)")) {
            my_putstr(EXIT_TWO_ADJACENT_OPERATOR_MSG);
            return (EXIT_TWO_ADJACENT_OPERATOR);
        }
        if (is_char_char_is_that_that(str, i, "*%/", "*/%)")) {
            my_putstr(EXIT_TWO_ADJACENT_OPERATOR_MSG);
            return (EXIT_TWO_ADJACENT_OPERATOR);
        }
        if (is_char_char_is_that_that(str, i, ")", "(")) {
            my_putstr(EXIT_TWO_ADJACENT_OPERATOR_MSG);
            return (EXIT_TWO_ADJACENT_OPERATOR);
        }
    }
    return (SUCCESSFUL_PASS);
}

int verif_in_parentesis(char *str)
{
    char *wanteds[] = {"(", "+-", ")"};
    for (int i = 0; str[i]; i++) {
        if (is_char_is_that_three(str, i, wanteds)) {
            my_putstr(EXIT_NOTHING_IN_PARENTESIS_MSG);
            return (EXIT_NOTHING_IN_PARENTESIS);
        }
        if (is_char_char_is_that_that(str, i, "(", ")*/%")) {
            my_putstr(EXIT_NOTHING_IN_PARENTESIS_MSG);
            return (EXIT_NOTHING_IN_PARENTESIS);
        }
    }
    return (verif_two_adjacent_operator(str));
}