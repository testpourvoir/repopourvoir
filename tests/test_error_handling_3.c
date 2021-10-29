/*
** EPITECH PROJECT, 2021
** test_error_handling_3.c
** File description:
** Unit tests for error_handling.c
*/

#include <criterion/criterion.h>
#include <my.h>

int error_handling(int ac , char **av);

int verif_number_of_parameters(int ac, char **av);

int verif_empty_msg(char *str);

int verif_other_char(char *str, char *wanted);

int verif_nbr_of_parentesis(char *str);

int verif_in_parentesis(char *str);

int verif_two_adjacent_operator(char *str);

Test(test_error_handling, only_one_parameters)
{
    int argc = 1;
    char *command = "./eval_expr";
    char *argv[] = {command};
    int result = error_handling(argc, argv);
    int expected = 84;
    cr_assert_eq(expected, result);
}

Test(test_error_handling, other_char)
{
    int argc = 2;
    char *command = "./eval_expr";
    char *parameter = "a";
    char *argv[] = {command, parameter};
    int result = error_handling(argc, argv);
    int expected = 84;
    cr_assert_eq(expected, result);
}

Test(test_error_handling, empty_parameter)
{
    int argc = 2;
    char *command = "./eval_expr";
    char *parameter = "";
    char *argv[] = {command, parameter};
    int result = error_handling(argc, argv);
    int expected = 84;
    cr_assert_eq(expected, result);
}

Test(test_error_handling, three_parentesis)
{
    int argc = 2;
    char *command = "./eval_expr";
    char *parameter = "(()";
    char *argv[] = {command, parameter};
    int result = error_handling(argc, argv);
    int expected = 84;
    cr_assert_eq(expected, result);

}

Test(test_error_handling, nothing_in_parentesis)
{
    int argc = 2;
    char *command = "./eval_expr";
    char *parameter = "()";
    char *argv[] = {command, parameter};
    int result = error_handling(argc, argv);
    int expected = 84;
    cr_assert_eq(expected, result);
}