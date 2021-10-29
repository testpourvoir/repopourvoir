/*
** EPITECH PROJECT, 2021
** make operate.c
** File description:
** return an str of the operate in all number beetween the bracket
*/

#include "include/my.h"
#include <stdlib.h>
int summands(char **str_ptr, int i);
char *my_int_to_str(int nb);

int make_operate(char *str_origin, int i)
{
    char *str_cpy;
    char *str_return;
    char *str_concat;
    int result = 0;
    char *result2;
    int a = 0;
    int j;
    int z;
    int b = 0;
    int h = 0;
    int e = 0;

    for (int i = 0; str_origin[i] != '\0'; i++) {
        if (str_origin[i] == '(')
            e += 1;
    }
    while (h != e - 1) {
        str_cpy = &str_origin[i + 1];
        str_concat = my_strdup(str_origin);
        for (j = 0; str_cpy[j] != ')' ; j++) {
            if (str_cpy[j] == '(') {
                b = j;
            }
        }
        str_return = my_strdup(str_cpy);
        str_return[j] = '\0';
        str_return = &str_return[b + 1];
        result = summands(&str_return, a);
        result2 = my_int_to_str(result);
        if (result > 0)
            str_concat[i + b + 1] = '\0';
        else
            str_concat[i + b] = '\0';
        my_strcat(str_concat, result2);
        for (z = j; str_cpy[z] != ')'; z++);
        str_cpy = &str_cpy[z + 1];
        str_origin = str_concat;
        h += 1;
    }
    str_origin = &str_origin[1];
    return (summands(&str_origin, 0));

}

