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

void print_turn(int match, int line, char **map)
{
    my_putstr("Player removed ");
    my_put_nbr(line);
    my_putstr(" match(es) from line ");
    my_put_nbr(match);
    my_putchar('\n');
    my_show_word_array(map);
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
    my_putstr("Matches: ");
    info.getline_error = getline(&info.match, &info.buff_size, stdin);
    while (analyze_match_move(info.match, map, info) != 0) {
        if (info.getline_error == -1)
            return (-2);
        return (-1);
    }
    play_move(map, my_getnbr(info.line), my_getnbr(info.match));
    print_turn(my_getnbr(info.line), my_getnbr(info.match), map);
    return (0);
}