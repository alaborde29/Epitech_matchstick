/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** matchstick
*/

#include "my.h"
#include "matchstick.h"

int matchstick(int n_line, int n_match)
{
    char **map = map_generator(n_line);

    my_show_word_array(map);
}