/*
** EPITECH PROJECT, 2022
** handle_o.c
** File description:
** handle_o
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

int replace_space_with_o(map_t *map, int i, int j, int k)
{
    if (i == map->co_o[k][0] && j == map->co_o[k][1]) {
        if (map->map2d[i][j] != 'P' && map->map2d[i][j] != 'X')
            map->map2d[i][j] = 'O';
        k++;
    }
    return k;
}

void check_space(map_t *map)
{
    int k = 0;

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width && k < map->nbr_of_o; j++) {
            k = replace_space_with_o(map, i, j, k);
        }
    }
}

void number_of_o(map_t *map)
{
    map->nbr_of_o = 0;

    for (int i = 0; map->map1d[i]; i++)
        if (map->map1d[i] == 'O')
            map->nbr_of_o += 1;
}

int stock_o(map_t *map, int i, int j, int k)
{
    if (map->map2d[i][j] == 'O') {
        map->co_o[k][0] = i;
        map->co_o[k][1] = j;
        k++;
    }
    return k;
}

void check_stock_o(map_t *map)
{
    int k = 0;

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            k = stock_o(map, i, j, k);
        }
    }
}
