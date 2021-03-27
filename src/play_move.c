/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** play_move
*/

#include "my.h"
#include "matchstick.h"
#include <stdlib.h>

void play_move(char **map, int line, int match)
{
    int i = line;
    int j = 0;
    int n = 0;

    while (map[i][j] != '\0')
        j++;
    while (map[i][j] != '|' && j != 0)
        j--;
    while (n != match) {
        map[i][j] = ' ';
        j--;
        n++;
    }
}