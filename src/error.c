/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** error
*/

#include "my.h"
#include "matchstick.h"

int error_handling(int ac, char **av)
{
    if (ac != 3)
        return (-1);
    if (my_str_isnum(av[1]) != 1 || my_str_isnum(av[2]) != 1)
        return (-1);
    if (my_strlen(av[2]) > 2)
        return (-1);
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 10)
        return (-1);
    if (my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 21)
        return (-1);
    return (0);
}