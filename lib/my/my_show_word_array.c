/*
** EPITECH PROJECT, 2020
** utilities
** File description:
** my_show_word_array
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
    return (0);
}