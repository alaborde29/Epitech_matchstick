/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** ia_turn
*/

#include "my.h"
#include "matchstick.h"
#include <stdlib.h>

int get_random(int n)
{
    int i = 0;
    int res = 0;
    int temp = 0;

    while (i != n) {
        temp = random();
        if ((temp / 2) == 1)
            res = res + 1;
        i++;
    }
    if (res == 0)
        res = 1;
    return (res);
}

int is_line_empty(char **map, int line)
{
    int i = 0;

    if (line == 0)
        return (1);
    while (map[line][i] != '\0') {
        if (map[line][i] == '|')
            return (0);
        i++;
    }
    return (1);
}

int count_match_in_line(char **map, int line)
{
    int i = 0;
    int n = 0;

    while (map[line][i] != '\0') {
        if (map[line][i] == '|')
            n++;
        i++;
    }
    return (n);
}

int is_match_number_valid(char **map, int line, int n_match, int match)
{
    int n = count_match_in_line(map, line);

    if (match > n_match || match == 0)
        return (-1);
    if (match > n)
        return (-1);
    return (0);
}

void ia_turn(char **map, int n_line, int n_match)
{
    int line = 0;
    int match = 0;

    my_putstr("AI's turn...\n");
    while (is_line_empty(map, line) == 1)
        line = get_random(n_line);
    while (is_match_number_valid(map, line, n_match, match) == -1) {
        if (n_match <= count_match_in_line(map, line))
            match = get_random(n_match);
        if (n_match > count_match_in_line(map, line))
            match = get_random(count_match_in_line(map, line));
    }
    my_putstr("AI removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    play_move(map, line, match);
}