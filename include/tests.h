/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** tests
*/

#ifndef TESTS_H_
#define TESTS_H_

int find_match_in_str(char *str);
int match_error(char **map, int line, int n_match);
int analyze_line_move(char *move, char **map, playturn_info_t info);
int analyze_match_move(char *move, char **map, playturn_info_t info);

#endif /* !TESTS_H_ */
