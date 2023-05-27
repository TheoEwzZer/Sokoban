/*
** EPITECH PROJECT, 2022
** handle_error.c
** File description:
** handle_error
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

void number_of_x(map_t *map)
{
    map->nbr_of_x = 0;

    for (int i = 0; map->map1d[i]; i++)
        if (map->map1d[i] == 'X')
            map->nbr_of_x += 1;
}

int check_player_in_map(map_t *map)
{
    int x = 0;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            x += map->map2d[i][j] == 'P' ? 1 : 0;
    }
    return x;
}

int contain_other_caracter(map_t *map)
{
    for (int i = 0; map->map1d[i]; i++) {
        if (map->map1d[i] != 'X' && map->map1d[i] != 'O' &&
            map->map1d[i] != 'P' && map->map1d[i] != '#' &&
            map->map1d[i] != ' ' && map->map1d[i] != '\n') {
            return 1;
        }
    }
    return 0;
}

void check_error(map_t *map)
{
    if (map->nbr_of_x != map->nbr_of_o) {
        endwin();
        exit(84);
    }
    if (check_player_in_map(map) != 1) {
        endwin();
        exit(84);
    }
    if (map->nbr_of_o == 0 || map->nbr_of_x == 0) {
        endwin();
        exit(84);
    }
    if (contain_other_caracter(map)) {
        endwin();
        exit(84);
    }
}
