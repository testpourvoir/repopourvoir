/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** A function that allocates memory and copies 
** the string given as argument in it.
*/

#include <stdlib.h>

char *my_strcpy(char *dest , char const *src);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *new = malloc(my_strlen(src) + 1);
    new = my_strcpy(new, src);
    return (new);
}
