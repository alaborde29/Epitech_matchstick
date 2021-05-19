/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** Test_matchstick
*/

#include "matchstick.h"
#include "tests.h"
#include <criterion/criterion.h>

Test(check_victory, not_win)
{
    char *map[4];
    char **verif = map_generator(2);
    
    map[0] = "*****"; 
    map[1] = "* | *"; 
    map[2] = "*|||*"; 
    map[3] = "*****"; 
    map[4] = 0; 


    cr_assert_str_eq(map[0], verif[0]);
    cr_assert_str_eq(map[1], verif[1]);
    cr_assert_str_eq(map[2], verif[2]);
    cr_assert_str_eq(map[3], verif[3]);
}

Test(check_num_of_match, ok)
{
    char *map[4];
    char **verif = map_generator(2);
    
    map[0] = "*****"; 
    map[1] = "* | *"; 
    map[2] = "*|||*"; 
    map[3] = "*****"; 
    map[4] = 0; 

    cr_assert_eq(count_match_in_line(map, 2), 3);
}

Test(match_error, is_move_possible)
{
    char *map[4];
    char **verif = map_generator(2);
    
    map[0] = "*****"; 
    map[1] = "* | *"; 
    map[2] = "*   *"; 
    map[3] = "*****"; 
    map[4] = 0; 

    cr_assert_eq(match_error(map, 1, 0), -1);
    cr_assert_eq(match_error(map, 1, 3), -1);
    cr_assert_eq(match_error(map, 1, 1), 0);
}

Test(line_error_gl, getline_error)
{
    char *map[4];
    char **verif = map_generator(2);
    playturn_info_t info;
    info.getline_error = -1;
    
    map[0] = "*****"; 
    map[1] = "* | *"; 
    map[2] = "*   *"; 
    map[3] = "*****"; 
    map[4] = 0; 

    cr_assert_eq(analyze_line_move("1", map, info), -1);
}

Test(line_error_oos, out_of_range)
{
    char *map[4];
    char **verif = map_generator(2);
    playturn_info_t info;
    info.getline_error = 0;
    info.limit.n_line = 2;
    
    map[0] = "*****"; 
    map[1] = "* | *"; 
    map[2] = "*   *"; 
    map[3] = "*****"; 
    map[4] = 0; 

    cr_assert_eq(analyze_line_move("30", map, info), -1);

}

Test(line_error_bd, bad_input)
{
    char *map[4];
    char **verif = map_generator(2);
    playturn_info_t info;
    info.getline_error = 0;
    
    map[0] = "*****"; 
    map[1] = "* | *"; 
    map[2] = "*   *"; 
    map[3] = "*****"; 
    map[4] = 0; 

    cr_assert_eq(analyze_line_move("A", map, info), -1);
}

Test(check_ac_size, ko)
{
    int ac = 1;
    char **av = 0;

    cr_assert_eq(-1, error_handling(ac, av));
}

Test(check_ac_size, ok)
{
    int ac = 3;
    char *av[3];

    av[1] = "4";
    av[2] = "4";
    av[0] = 0;

    cr_assert_eq(0, error_handling(ac, av));
}