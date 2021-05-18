/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** Test_matchstick
*/

#include "matchstick.h"
#include <criterion/criterion.h>

Test(check_victory, not_win)
{
    int ac = 1;
    char **av = 0;

    cr_assert_eq(-1, error_handling(ac, av));
}