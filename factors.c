/*
** EPITECH PROJECT, 2021
** factor.c
** File description:
** A function that returns the product of the expression given as parameter
*/

#include <my.h>

int summands(char **str_ptr, int i);

int next_number(char ** str_ptr, int *i)
{
    while (str_ptr[0][*i] >= '0') {
        *i += 1;
    }
}

int add_my_res(char op, int *i, char **str_ptr, int res)
{
    int nb;
    if (!(str_ptr[0][*i] == '-')) {
        *i = *i + 1;
    }
    if (op == '*') {
        nb = my_getnbr(&(str_ptr[0][*i]));
        if (str_ptr[0][*i] == '-') {
            *i = *i + 1;
        }
        res = res * nb;
    } else if (op == '/') {
        nb = my_getnbr(&(str_ptr[0][*i]));
        res = res / nb;
    } else {
        nb = my_getnbr(&(str_ptr[0][*i]));
        res = res % nb;
    }
    return (res);
}

int factors(char ** str_ptr, int i)
{
    int first_number = my_getnbr(&(str_ptr[0][i]));
    int res;
    char op;

    i = i + 1;
    res = first_number;
    while (1) {
        next_number(str_ptr, &i);
        op = str_ptr[0][i];
        if (op == '*' || op == '/' || op == '%') {
            (str_ptr[0][i + 1] == '-') ? i = i + 1 : 0;
            res = add_my_res(op, &i, str_ptr, res);
        }
        else if (op == '+' || op == '-')
            return (res + summands(str_ptr, i));
        else
            return (res);
    }
}
