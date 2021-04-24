/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** input_error
*/

#include "matchstick.h"
#include "my.h"

int analyze_line_move(char *move, char **map, playturn_info_t info)
{
    if (my_str_isnum(move) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-1);
    }
    if ((info.getline_error == -1 || my_getnbr(move) <= 0 || \
    my_getnbr(move) > info.limit.n_line)) {
        if (info.getline_error == -1)
            my_putchar('\n');
        my_putstr("Error: this line is out of range\n");
        return (-1);
    }
    return (0);
}

int match_error(char **map, int line, int n_match)
{
    int n = 0;

    if (n_match == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    }
    while (map[line][n] != '\n' && map[line][n] != '\0')
        n++;
    if (n < n_match) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    return (0);
}

int analyze_match_move(char *move, char **map, playturn_info_t info)
{
    if (my_str_isnum(move) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-1);
    }
    if ((info.getline_error == -1 || my_getnbr(move) <= 0 || \
    my_getnbr(move) > info.limit.n_match)) {
        my_putstr("You cannot remove more than ");
        my_put_nbr(info.limit.n_match);
        my_putstr(" matches per turn\n");
        return (-1);
    }
    if (match_error(map, my_getnbr(info.line), my_getnbr(move)) == -1)
        return (-1);
    return (0);
}