/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** player_turn
*/

#include "my.h"
#include "matchstick.h"
#include <stdio.h>

limit_t init_limit(int n_line, int n_match)
{
    limit_t limit;

    limit.n_line = n_line;
    limit.n_match = n_match;
    return (limit);
}

playturn_info_t init_playturn_info(int n_line, int n_match)
{
    playturn_info_t info;

    info.limit = init_limit(n_line, n_match);
    info.buff_size = 15;
    info.getline_error = 0;
    info.line = 0;
    info.match = 0;
    return (info);
}

int player_turn(char **map, int n_line, int n_match)
{
    playturn_info_t info = init_playturn_info(n_line, n_match);

    my_putstr("Line: ");
    info.getline_error = getline(&info.line, &info.buff_size, stdin);
    while (analyze_line_move(info.line, map, info) != 0) {
        if (info.getline_error == -1)
            return (-2);
        my_putstr("Line: ");
        info.getline_error = getline(&info.line, &info.buff_size, stdin);
    }
    my_putstr("Match: ");
    info.getline_error = getline(&info.match, &info.buff_size, stdin);
    while (analyze_match_move(info.match, map, info) != 0) {
        if (info.getline_error == -1)
            return (-2);
        return (-1);
    }
    play_move(map, my_getnbr(info.line), my_getnbr(info.match));
    return (0);
}