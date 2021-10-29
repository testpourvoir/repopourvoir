/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** A function that reverses a string.
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int len_word = my_strlen(str) - 1;
    char temp;

    for (; i <= len_word / 2; i++) {
        temp = str[i];
        str[i] = str[len_word - i];
        str[len_word - i] = temp;
    }
    return (str);
}
