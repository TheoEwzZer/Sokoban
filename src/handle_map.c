/*
** EPITECH PROJECT, 2022
** handle_map.c
** File description:
** handle_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

void getwidth1d(map_t *map)
{
    map->width = 0;
    int j = 0;

    for (int i = 0; map->map1d[i] != '\0'; i++) {
        if (map->map1d[i] == '\n') {
            map->width = j > map->width ? j : map->width;
            j = 0;
        } else {
            j++;
        }
    }
}

void getheight1d(map_t *map)
{
    map->height = 0;

    for (int i = 0; map->map1d[i]; i++) {
        if (map->map1d[i] == '\n')
            map->height += 1;
    }
}

void load_file_in_memory(map_t *map, char const *filepath)
{
    struct stat buf;

    if (stat(filepath, &buf) == -1)
        exit(84);
    int size = buf.st_size;
    map->map1d = malloc(sizeof(char) * (size + 1));
    map->map1d[size] = '\0';
    int fd = open(filepath, O_RDONLY);
    if (fd == -1 || !size || read(fd, map->map1d, size) == -1)
        exit(84);
    close(fd);
}

void get_player_position(pos_t *pos, map_t *map, int j, int k)
{
    if (map->map2d[j][k] == 'P') {
        pos->y = j;
        pos->x = k;
    }
}

void load_file_in_memory_2d(pos_t *pos, map_t *map)
{
    map->map2d = malloc(sizeof(char *) * (map->height + 1));

    map->map2d[map->height] = '\0';
    if (!map->map2d)
        exit(84);
    int i = 0;
    for (int j = 0; j < map->height; j++) {
        map->map2d[j] = malloc(sizeof(char) * (map->width + 1));
        map->map2d[j][map->width] = 0;
        for (int k = 0; map->map1d[i] != '\n' && map->map1d[i] != '\0'; k++) {
            map->map2d[j][k] = map->map1d[i];
            get_player_position(pos, map, j, k);
            i++;
        }
        i++;
    }
}
