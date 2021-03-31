/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** game
*/

#include "my.h"
#include "matchstick.h"
#include <stdlib.h>

void print_victory_message(int exit)
{
    if (exit == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    if (exit == 2)
        my_putstr("You lost, too bad...\n");
}

int game_loop(char **map, int n_line, int n_match)
{
    int exit = 0;

    my_show_word_array(map);
    my_putstr("\n");
    while (exit < 1) {
        exit = game_statut(map, 2);
        if (exit != 0)
            break;
        my_putstr("Your turn:\n");
        player_turn(map, n_line, n_match);
        my_show_word_array(map);
        exit = game_statut(map, 1);
        if (exit != 0)
            break;
        ia_turn(map, n_line, n_match);
        my_show_word_array(map);
    }
    print_victory_message(exit);
    return (exit);
}