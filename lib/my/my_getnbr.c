/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** my_getnbr
*/

void first_numberf(char const *str, int *index, int *neg)
{
    while (!(str[*index] >= 48 && str[*index] <= 57)) {
        if (str[*index] == '-') {
            *neg = 1;
        } else {
            *neg = 0;
        }
        *index = *index + 1;
    }
}

void transform_ifneg(int *number, int neg)
{
    if (neg == 1) {
        *number = - *number;
    }
}

int my_getnbr(char const *str)
{
    int index = 0;
    int unit = 1;
    int number = 0;
    int neg = 0;
    int first_number = 0;

    first_numberf(str, &index, &neg);
    first_number = index;
    while (str[index] >= 48 && str[index] <= 57) {
        number = number * 10 + str[index] - 48;
        index = index + 1;
        if (number > 2147483647 && neg == 0) {
            return (0);
        } else if (number > 2147483648 && neg == 1) {
            return (0);
        }
    }
    transform_ifneg(&number, neg);
    return number;
}
