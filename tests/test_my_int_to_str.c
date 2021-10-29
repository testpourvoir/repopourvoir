/*
** EPITECH PROJECT, 2021
** test_int_to_str.c
** File description:
** Unit tests for int_to_str.c
*/

#include <criterion/criterion.h>
#include <my.h>

char *my_int_to_str(int nb);

Test(test_my_int_to_str, positif_nb)
{
    int a = 1000;
    char * result;
    result = my_int_to_str(a);
    char *expected = "1000";
    cr_assert_str_eq(expected, result);
}

Test(test_my_int_to_str, null_nb)
{
    int a = 0;
    char * result;
    result = my_int_to_str(a);
    char *expected = "0";
    cr_assert_str_eq(expected, result);
}

Test(test_my_int_to_str, negativ_nb)
{
    int a = -1000;
    char * result;
    result = my_int_to_str(a);
    char *expected = "-1000";
    cr_assert_str_eq(expected, result);
}