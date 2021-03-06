/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** game
*/

#include "my.h"
#include "matchstick.h"
#include <stdlib.h>

int find_max_line_size(int n_line)
{
    int i = 0;
    int n = 1;

    while (i != n_line) {
        n = n + 2;
        i++;
    }
    return (n);
}

void print_victory_message(int exit)
{
    if (exit == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    if (exit == 2)
        my_putstr("You lost, too bad...\n");
}

int player_loop(char **map, int n_line, int n_match, int ctrld)
{
    my_putstr("Your turn:\n");
    ctrld = player_turn(map, n_line, n_match);
    while (ctrld == -1)
        ctrld = player_turn(map, n_line, n_match);
    if (ctrld == -2)
        return (-2);
    return (0);
}

int game_loop(char **map, int n_line, int n_match)
{
    int exit = 0;
    int ctrld = 0;

    my_show_word_array(map);
    while (exit < 1) {
        exit = game_statut(map, 2);
        if (exit != 0)
            break;
        ctrld = player_loop(map, n_line, n_match, ctrld);
        if (ctrld == -2)
            return (0);
        exit = game_statut(map, 1);
        if (exit != 0)
            break;
        ia_turn(map, n_line, n_match);
    }
    print_victory_message(exit);
    return (exit);
}