/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** matchstick
*/

#include <stddef.h>

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct limit_s
{
    int n_line;
    int n_match;
    
}limit_t;

typedef struct playturn_info_s
{
    char *line;
    char *match;
    size_t buff_size;
    int getline_error;
    limit_t limit;
}playturn_info_t;

int find_max_line_size(int n_line);
int error_handling(int ac, char **av);
int matchstick(int n_line, int n_match);
char **map_generator(int n_line);
int game_statut(char **map, int player);
void play_move(char **map, int line, int match);
int count_match_in_line(char **map, int line);
int is_line_empty(char **map, int line);
int is_match_number_valid(char **map, int line, int n_match, int match);
int player_turn(char **map, int n_line, int n_match);
int game_loop(char **map, int n_line, int n_match);
void ia_turn(char **map, int n_line, int n_match);
int analyze_match_move(char *move, char **map, playturn_info_t info);
int analyze_line_move(char *move, char **map, playturn_info_t info);
#endif /* !MATCHSTICK_H_ */