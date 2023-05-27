/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** sokoban
*/

#include "my.h"

#ifndef SOKOBAN_H_

    #define SOKOBAN_H_

typedef struct position {
    int x;
    int y;
} pos_t;

typedef struct sokoban_map {
    int height;
    int width;
    int **co_o;
    char **map2d;
    char *map1d;
    int nbr_of_o;
    int nbr_of_x;
} map_t;

void move_p(pos_t *pos, map_t *map, int key, char **map2);
void getwidth1d(map_t *map);
void getheight1d(map_t *map);
void load_file_in_memory(map_t *map, char const *filepath);
void load_file_in_memory_2d(pos_t *pos, map_t *map);
void check_space(map_t *map);
void number_of_o(map_t *map);
void check_stock_o(map_t *map);
void check_win(map_t *map, int y_pos, int x_pos);
void check_lose(map_t *map, int y_pos, int x_pos);
void number_of_x(map_t *map);
void check_error(map_t *map);

#endif /* SOKOBAN_H_ */
