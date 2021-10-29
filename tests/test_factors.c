/*
** EPITECH PROJECT, 2021
** test_factors.c
** File description:
** Unit tests for factors.c
*/

#include <criterion/criterion.h>
#include <my.h>

int factors(char ** str_ptr, int i);

int summands(char ** str_ptr, int i);

Test(test_factor, divide_of_two_positive_number)
{
    char *argv = "1*-10";
    int i = 0;
    int result = factors(&argv, i);
    int expected = -10;
    cr_assert_eq(expected, result);
}

Test(test_factor, multiadd_of_two_positive_number)
{
    char *argv = "10*1+10-11*2-10";
    int i = 0;
    int result = factors(&argv, i);
    int expected = -12;
    cr_assert_eq(expected, result);
}

Test(test_factor, divid_of_three_positive_number)
{
    char *argv = "100/2/5";
    int i = 0;
    int result = factors(&argv, 0);
    int expected = 10;
    cr_assert_eq(expected, result);
}

Test(test_factor, modulo_of_two_positive_number)
{
    char *argv = "10+100/5%10+10+10*1";
    int i = 0;
    int result = factors(&argv, 0);
    int expected = 30;
    cr_assert_eq(expected, result);
}