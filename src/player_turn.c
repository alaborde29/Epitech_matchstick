/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** player_turn
*/

#include "my.h"
#include "matchstick.h"
#include <stdio.h>

int analyze_move(char *move, int n_line, int n_match, int mode)
{
    my_putstr(move);
    if (my_str_isnum(move) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-1);
    }
    if (my_getnbr(move) > n_line && mode == 1) {
        my_putstr("\nError: this line is out of range\n");
        return (-1);
    }
    if (my_getnbr(move) > n_match && mode == 2) {
        my_putstr("\nYou cannot remove more than ");
        my_put_nbr(n_match);
        my_putstr(" matches per turn\n");
        return (-1);
    }
    return (0);
}

void player_turn(char **map, int n_line, int n_match)
{
    char *line = 0;
    char *match = 0;
    size_t buff_size = 5;
    int pos;

    my_putstr("Line: ");
    getline(&line, &buff_size, stdin);
    while (analyze_move(line, n_line, n_match, 1) == -1) {
        my_putstr("Line: ");
        getline(&line, &buff_size, stdin);
    }
    my_putstr("Match: ");
    getline(&match, &buff_size, stdin);
    while (analyze_move(match, n_line, n_match, 2) == -1) {
        my_putstr("Match: ");
        getline(&match, &buff_size, stdin);
    }
    play_move(map, my_getnbr(line), my_getnbr(match));
}