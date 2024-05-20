/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** generate_map
*/

#include "zappy_server.h"

map_tile_t **generate_map_tile(int x, int y)
{
    int i = 0;
    int j = 0;
    map_tile_t **map = calloc(sizeof(map_tile_t *), (y + 1));

    for (i = 0; i < y; i += 1) {
        map[i] = calloc(sizeof(map_tile_t), (x + 1));
        for (j = 0; j < x; j += 1) {
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

void free_map_tile(map_tile_t **map_tile)
{
    int i = 0;
    int j = 0;

    for (i = 0; map_tile[i] != NULL; i += 1) {
        for (j = 0; map_tile[i][j].x != -1; j += 1) {
            free_char_tab_list(&map_tile[i][j].resources);
        }
        free(map_tile[i]);
    }
    free(map_tile);
}