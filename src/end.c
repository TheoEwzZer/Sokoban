/*
** EPITECH PROJECT, 2022
** end.c
** File description:
** end
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

int win(map_t *map, int i, int j, int k)
{
    if (i == map->co_o[k][0] && j == map->co_o[k][1]) {
        if (map->map2d[i][j] == 'X')
            k++;
    }
    return k;
}

void check_win(map_t *map, int y_pos, int x_pos)
{
    int k = 0;

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width && k < map->nbr_of_o; j++) {
            k = win(map, i, j, k);
        }
    }
    if (k == map->nbr_of_o) {
        endwin();
        clear();
        for (int i = 0; map->map2d[i]; i++)
            mvprintw(y_pos + i, x_pos, "%s\n", map->map2d[i]);
        refresh();
        exit(0);
    }
}

int is_stuck(map_t *map, int i, int j)
{
    if (map->map2d[i][j] == '#' || map->map2d[i][j] == 'X')
        return 1;
    return 0;
}

int check_stuck(map_t *map, int i, int j, int k)
{
    if (map->map2d[i][j] == 'X') {
        if (is_stuck(map, i + 1, j) && is_stuck(map, i, j + 1))
            return k + 1;
        if (is_stuck(map, i - 1, j) && is_stuck(map, i, j + 1))
            return k + 1;
        if (is_stuck(map, i + 1, j) && is_stuck(map, i, j - 1))
            return k + 1;
        if (is_stuck(map, i - 1, j) && is_stuck(map, i, j - 1))
            return k + 1;
    }
    return k;
}

void check_lose(map_t *map, int y_pos, int x_pos)
{
    int k = 0;

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            k = check_stuck(map, i, j, k);
        }
    }
    if (k == map->nbr_of_o) {
        endwin();
        clear();
        for (int i = 0; map->map2d[i]; i++)
            mvprintw(y_pos + i, x_pos, "%s\n", map->map2d[i]);
        refresh();
        exit(1);
    }
}
