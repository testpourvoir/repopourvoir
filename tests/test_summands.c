/*
** EPITECH PROJECT, 2021
** test_summands.c
** File description:
** Unit tests for summands.c
*/

#include <criterion/criterion.h>

int summands(char ** str_ptr, int i);

Test(test_summands, sum_of_two_positive_number)
{
    char *argv = "123+123";
    int result = summands(&argv, 0);
    int expected = 246;
    cr_assert_eq(expected, result);
}

Test(test_summands, substract_of_two_positive_number)
{
    char *argv = "246-123";
    int result = summands(&argv, 0);
    int expected = 123;
    cr_assert_eq(expected, result);
}

Test(test_summands, sum_of_multiple_positive_number)
{
    char *argv = "123+123+420";
    int result = summands(&argv, 0);
    int expected = 666;
    cr_assert_eq(expected, result);
}

Test(test_summands, sum_of_multiple_negative_number)
{
    char *argv = "-123-123-420";
    int result = summands(&argv, 0);
    int expected = -666;
    cr_assert_eq(expected, result);
}

Test(test_summands, sum_of_random_number)
{
    char *argv = "123-123+420-100-100-100+201";
    int result = summands(&argv, 0);
    int expected = 321;
    cr_assert_eq(expected, result);
}