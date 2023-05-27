/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

void help(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            my_putstr("USAGE\n");
            my_putstr("\t./my_sokoban\n");
            my_putstr("DESCRIPTION\n");
            my_putstr("\tmap file representing the warehouse map, ");
            my_putstr("containing '#' for walls,\n");
            my_putstr("\t'P' for the player, 'X' for boxes and ");
            my_putstr("'O' for storage locations.\n");
            exit(0);
        }
    } else {
        exit(84);
    }
}

int check_terminal_size(map_t *map)
{
    int x = 0;
    int y = 0;
    char *str = "Please enlarge the terminal";

    getmaxyx(stdscr, y, x);
    if (x < map->width || y < map->height) {
        clear();
        mvprintw(y / 2, (x - my_strlen(str)) / 2, str);
        refresh();
        return 1;
    }
    return 0;
}

void game(pos_t *pos, map_t *map)
{
    int x = 0;
    int y = 0;

    if (!check_terminal_size(map)) {
        clear();
        getmaxyx(stdscr, y, x);
        int y_pos = (y - map->height) / 2;
        int x_pos = (x - map->width) / 2;
        for (int i = 0; map->map2d[i]; i++)
            mvprintw(y_pos + i, x_pos, "%s\n", map->map2d[i]);
        int key = getch();
        move_p(pos, map, key, map->map2d);
        check_space(map);
        check_win(map, y_pos, x_pos);
        check_lose(map, y_pos, x_pos);
        refresh();
    }
}

void init(pos_t *pos, map_t *map, char **argv)
{
    load_file_in_memory(map, argv[1]);
    getheight1d(map);
    getwidth1d(map);
    load_file_in_memory_2d(pos, map);
    number_of_o(map);
    number_of_x(map);
    map->co_o = malloc(sizeof(int *) * map->nbr_of_o);
    for (int i = 0; i < map->nbr_of_o; i++)
        map->co_o[i] = malloc(sizeof(int) * 2);
}

int main(int argc, char **argv)
{
    help(argc, argv);
    map_t *map = malloc(sizeof(map_t));
    pos_t *pos = malloc(sizeof(pos_t));
    init(pos, map, argv);
    check_error(map);
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    check_stock_o(map);
    while (1)
        game(pos, map);
    endwin();
    free(map);
    free(pos);
    return 1;
}
