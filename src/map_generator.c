/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** map_generator
*/

#include "my.h"
#include "matchstick.h"
#include <stdlib.h>

int max_line_size(int n_line)
{
    int i = 0;
    int n = 1;

    while (i != n_line) {
        n = n + 2;
        i++;
    }
    return (n);
}

void put_border_in_tab(char **map, int n_line)
{
    int i = 0;
    int j = 0;

    while (i != max_line_size(n_line)) {
        map[0][i] = '*';
        map[n_line + 1][i] = '*';
        i++;
    }
    map[0][i] = '\0';
    map[n_line + 1][i] = '\0';
    while (j != n_line + 1) {
        map[j][0] = '*';
        map[j][max_line_size(n_line) - 1] = '*';
        j++;
    }
}

void fill_map(char **map, int n_line)
{
    int i = 1;
    int j = (max_line_size(n_line) + 2) / 2 - 1;
    int n_match = 1;
    int limit = j - n_match;

    while (i != n_line + 1) {
        while (j != limit) {
            map[i][j] = '|';
            j--;
        }
        n_match = n_match + 2;
        j = j + n_match - 1;
        limit = j - n_match;
        i++;
    }
}

char **map_generator(int n_line)
{
    char **map = malloc(sizeof(char *) * (n_line + 2 + 1));
    int i = 0;
    int j = 0;

    while (i != n_line + 2) {
        map[i] = malloc(sizeof(char) * (max_line_size(n_line) + 2 + 1));
        while (j != max_line_size(n_line)) {
            map[i][j] = ' ';
            j++;
        }
        map[i][j] = '\0';
        j = 0;
        i++;
    }
    map[i] = 0;
    put_border_in_tab(map, n_line);
    fill_map(map, n_line);
    my_show_word_array(map);
    return (map);
}