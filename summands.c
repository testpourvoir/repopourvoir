/*
** EPITECH PROJECT, 2021
** summands.c
** File description:
** A function that returns the sum of the expression given as parameter.
*/

#include <my.h>

int factors(char ** str_ptr, int i);

char get_next_operator(char **str_ptr, int i)
{
    int parentheses = 0;
    if (str_ptr[0][i] == '(') {
        parentheses += 1;
    }
    i += 1;
    while (str_ptr[0][i] >= '0' || parentheses != 0) {
        if (str_ptr[0][i] == '(') {
            parentheses += 1;
        } else if (str_ptr[0][i] == ')') {
            parentheses -= 1;
        }
        i = i + 1;
    }
    if (str_ptr[0][i]) {
        return (str_ptr[0][i]);
    }
    return (0);
}

int summands(char **str_ptr, int i)
{
    char next_operator;
    int j = i;
    i = i + 1;

    while (str_ptr[0][i] >= '0') {
        i = i + 1;
    }
    if (str_ptr[0][i] == '+' || str_ptr[0][i] == '-') {
        next_operator = get_next_operator(str_ptr, i + 1);
        if (next_operator == '+' || next_operator == '-' || !next_operator) {
            return (my_getnbr(&(str_ptr[0][j])) + summands(str_ptr, i));
        } else {
            return (my_getnbr(&(str_ptr[0][j])) + factors(str_ptr, i));
        }
    } else {
        if (!str_ptr[0][i]) {
            return (my_getnbr(&(str_ptr[0][j])));
        }
        return (factors(str_ptr, j));
    }
}