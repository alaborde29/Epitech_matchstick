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
    char *map[4];
    char **verif = map_generator(2);
    
    map[0] = "*****"; 
    map[1] = "* | *"; 
    map[2] = "*|||*"; 
    map[3] = "*****"; 
    map[4] = 0; 


    cr_assert_str_eq(map[0], verif[0]);
    cr_assert_str_eq(map[1], verif[1]);
    cr_assert_str_eq(map[2], verif[2]);
    cr_assert_str_eq(map[3], verif[3]);
}

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