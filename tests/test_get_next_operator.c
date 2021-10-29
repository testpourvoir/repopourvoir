/*
** EPITECH PROJECT, 2021
** test_get_next_operator.c
** File description:
** Unit tests for get_next_operator.c
*/

#include <criterion/criterion.h>
#include <my.h>

char get_next_operator(char **str_ptr, int i);

Test(test_get_next_operator, get_next_operator_simple)
{
    char *argv = "123+123";
    char result = get_next_operator(&argv, 0);
    char expected = '+';
    cr_assert_eq(expected, result);
}

Test(test_get_next_operator, get_next_operator_parentheses)
{
    char *argv = "(123+123)-2";
    char result = get_next_operator(&argv, 0);
    my_putchar(result);
    char expected = '-';
    cr_assert_eq(expected, result);
}

Test(test_get_next_operator, get_next_operator_multiple_parentheses)
{
    char *argv = "(123-(3+123))-2";
    char result = get_next_operator(&argv, 0);
    my_putchar(result);
    char expected = '-';
    cr_assert_eq(expected, result);
}