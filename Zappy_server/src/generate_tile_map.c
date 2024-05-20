/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** generate_map
*/

#include "zappy_server.h"

map_tile_t **generate_tile_map(int x, int y)
{
    int i = 0;
    int j = 0;
    map_tile_t **map = calloc(sizeof(map_tile_t *), (y + 1));

    for (i = 0; i < y; i++) {
        map[i] = calloc(sizeof(map_tile_t), (x + 1));
        for (j = 0; j < x; j++) {
            map[i][j].x = j;
            map[i][j].y = i;
            TAILQ_INIT(&map[i][j].resources);
        }
        map[i][j].x = -1;
        map[i][j].y = -1;
    }
    map[i] = NULL;
    return map;
}