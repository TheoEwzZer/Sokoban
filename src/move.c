/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

void move_right(pos_t *pos, map_t *map2, char **map)
{
    if (pos->x + 1 >= map2->width)
        return;
    if (map[pos->y][pos->x + 1] == ' ' || map[pos->y][pos->x + 1] == 'O') {
        map[pos->y][pos->x + 1] = 'P';
        map[pos->y][pos->x] = ' ';
        pos->x++;
        return;
    }
    if (map[pos->y][pos->x + 1] == 'X') {
        if (map[pos->y][pos->x + 2] == ' ' || map[pos->y][pos->x + 2] == 'O') {
            map[pos->y][pos->x + 2] = 'X';
            map[pos->y][pos->x + 1] = 'P';
            map[pos->y][pos->x] = ' ';
            pos->x++;
        }
    }
}

void move_down(pos_t *pos, map_t *map2, char **map)
{
    if (pos->y + 1 >= map2->height)
        return;
    if (map[pos->y + 1][pos->x] == ' ' || map[pos->y + 1][pos->x] == 'O') {
        map[pos->y + 1][pos->x] = 'P';
        map[pos->y][pos->x] = ' ';
        pos->y++;
        return;
    }
    if (map[pos->y + 1][pos->x] == 'X') {
        if (map[pos->y + 2][pos->x] == ' ' || map[pos->y + 2][pos->x] == 'O') {
            map[pos->y + 2][pos->x] = 'X';
            map[pos->y + 1][pos->x] = 'P';
            map[pos->y][pos->x] = ' ';
            pos->y++;
        }
    }
}

void move_left(pos_t *pos, char **map)
{
    if (pos->x - 1 < 0)
        return;
    if (map[pos->y][pos->x - 1] == ' ' || map[pos->y][pos->x - 1] == 'O') {
        map[pos->y][pos->x - 1] = 'P';
        map[pos->y][pos->x] = ' ';
        pos->x--;
        return;
    }
    if (map[pos->y][pos->x - 1] == 'X') {
        if (map[pos->y][pos->x - 2] == ' ' || map[pos->y][pos->x - 2] == 'O') {
            map[pos->y][pos->x - 2] = 'X';
            map[pos->y][pos->x - 1] = 'P';
            map[pos->y][pos->x] = ' ';
            pos->x--;
        }
    }
}

void move_up(pos_t *pos, char **map)
{
    if (pos->y - 1 < 0)
        return;
    if (map[pos->y - 1][pos->x] == ' ' || map[pos->y - 1][pos->x] == 'O') {
        map[pos->y - 1][pos->x] = 'P';
        map[pos->y][pos->x] = ' ';
        pos->y--;
        return;
    }
    if (map[pos->y - 1][pos->x] == 'X') {
        if (map[pos->y - 2][pos->x] == ' ' || map[pos->y - 2][pos->x] == 'O') {
            map[pos->y - 2][pos->x] = 'X';
            map[pos->y - 1][pos->x] = 'P';
            map[pos->y][pos->x] = ' ';
            pos->y--;
        }
    }
}

void move_p(pos_t *pos, map_t *map2, int key, char **map)
{
    if (key == KEY_RIGHT)
        move_right(pos, map2, map);
    if (key == KEY_DOWN)
        move_down(pos, map2, map);
    if (key == KEY_LEFT)
        move_left(pos, map);
    if (key == KEY_UP)
        move_up(pos, map);
    if (key == ' ')
        load_file_in_memory_2d(pos, map2);
}
