/*
** EPITECH PROJECT, 2021
** my_init_to_str.c
** File description:
** transform int into str
*/

#include <stdlib.h>
#include <my.h>

char *transform_my_int(int max, int number, int i, char *str)
{
    while (max != 1) {
        number = number - number / max * max;
        max = max / 10;
        str[i] = number / max + '0';
        i += 1;
    }
    return (str);
}

char init_my_str(int *number, char buffer, int *max, int *nb_len)
{
    if (*number < 0) {
        buffer = '-';
        *number = - *number;
    }
    while (*number / *max != 0) {
        *max = *max * 10;
        *nb_len += 1;
    }
    return (buffer);
}

char *my_int_to_str(int nb)
{
    int max = 1;
    int number = nb;
    int nb_len = 0;
    char *str;
    char buffer;
    int i = 0;

    if (number == 0) {
        str = "0";
        return (str);
    }
    buffer = init_my_str(&number, buffer, &max, &nb_len);
    str = malloc(sizeof(char) * (nb_len + 2));
    if (buffer == '-') {
        str[i] = buffer;
        i += 1;
    }
    str = transform_my_int(max, number, i, str);
    return (str);
}