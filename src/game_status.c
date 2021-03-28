/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** game_status
*/

#include "matchstick.h"
#include "my.h"

int find_match_in_str(char *str)
{
    int i = 0;
    int n = 0;

    while (str[i] != '\0') {
        if (str[i] == '|')
            n++;
        i++;
    }
    return (n);
}

int game_statut(char **map, int player)
{
    int i = 0;
    int n = 0;

    while (map[i]) {
        n = n + find_match_in_str(map[i]);
        i++;
    }
    my_put_nbr(n);
    if (n == 0 && player == 1)
        return (1);
    if (n == 0 && player == 2)
        return (2);
    return (0);
}