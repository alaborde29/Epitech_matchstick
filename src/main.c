/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-infinadd-alexandre.laborde
** File description:
** main
*/

#include "my.h"
#include "matchstick.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) != 0)
        return (84);
    return (matchstick(my_getnbr(av[1]), my_getnbr(av[2])));
}