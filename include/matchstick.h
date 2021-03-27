/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-alexandre.laborde
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

int error_handling(int ac, char **av);
int matchstick(int n_line, int n_match);
char **map_generator(int n_line);
int game_statut(char **map, int player);
void play_move(char **map, int line, int match);
int count_match_in_line(char **map, int line);
int is_line_empty(char **map, int line);
int is_match_number_valid(char **map, int line, int n_match, int match);
void player_turn(char **map, int n_line, int n_match);
int game_loop(char **map, int n_line, int n_match);
void ia_turn(char **map, int n_line, int n_match);

#endif /* !MATCHSTICK_H_ */