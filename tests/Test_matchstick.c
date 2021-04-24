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
    char *map[] = {"+++++++++",
                "|.......|",
                "|.......|",
                "|.......|",
                "|.......|",
                "+++++++++"};
    connect_t connect;
    int result = 0;

    connect.player_one = 'X';
    connect.player_two = 'O';
    connect.size_x = my_strlen(map[1]) - 2;
    connect.size_y = 6;
    result = check_victory(map, connect);
    cr_assert_eq(result, 0);
}