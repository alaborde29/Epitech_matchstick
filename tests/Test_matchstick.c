/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** Test_matchstick
*/

#include "matchstick.h"
#include <criterion/criterion.h>

Test(check_ac_size, ko)
{
    int ac = 1;
    char **av = 0;

    cr_assert_eq(-1, error_handling(ac, av));
}

Test(check_ac_size, ok)
{
    int ac = 3;
    char *av[3];

    av[1] = "4";
    av[2] = "4";
    av[0] = 0;

    cr_assert_eq(0, error_handling(ac, av));
}