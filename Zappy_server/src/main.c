/*
** EPITECH PROJECT, 2024
** my_scripts
** File description:
** main
*/

#include "zappy_server.h"

void shuffle_int_array(int **array, int n)
{
    int *tmp = NULL;
    int index = 0;

    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            index = rand() % n;
            tmp = array[index];
            array[index] = array[i];
            array[i] = tmp;
        }
    }
}

int **generate_possible_coordinate(int x, int y)
{
    int index = 0;
    int **possible_coordinate = calloc(sizeof(int *), (x * y) + 1);

    for (int i = 0; i < x; i += 1){
        for (int j = 0; j < y; j += 1){
            possible_coordinate[index] = calloc(sizeof(int), 2);
            possible_coordinate[index][0] = i;
            possible_coordinate[index][1] = j;
            index += 1;
        }
    }
    possible_coordinate[index] = NULL;
    return possible_coordinate;
}

void free_int_array(int **possible_coordinate)
{
    for (int i = 0; possible_coordinate[i] != NULL; i += 1) {
        free(possible_coordinate[i]);
    }
    free(possible_coordinate);
}

void put_resource_on_map_tile(map_tile_t **map_tile, struct char_tab_head * const head,
    int x, int y)
{
    int **possible_coordinate = generate_possible_coordinate(x, y);

    shuffle_int_array(possible_coordinate, x * y);

    char_tab_t *tmp = TAILQ_FIRST(head);
    char_tab_t *tmp2 = NULL;
    int index = 0;

    for (int i = 0; i < x; i += 1) {
        for (int j = 0; j < y; j += 1) {
            tmp2 = calloc(sizeof(char_tab_t), 1);
            tmp2->str = strdup(tmp->str);
            tmp = TAILQ_NEXT(tmp, next);
            TAILQ_INSERT_TAIL(&(map_tile[possible_coordinate[index][1]]
                [possible_coordinate[index][0]]).resources, tmp2, next);
            if (tmp == NULL)
                return;
            index += 1;
        }
    }
    free_int_array(possible_coordinate);
    return;
}

static void help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 "
        "... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf(
        "\tfreq\t\tis the reciprocal of time unit for execution of actions\n");
}

void clear_all(args_config_t *args, struct char_tab_head *resourse_list)
{
    free_args_config(args);
    free_char_tab_list(resourse_list);
    free(resourse_list);
}

int main(int argc, char **argv)
{
    args_config_t *args = NULL;
    struct char_tab_head *resourse_list = NULL;
    srand(time(NULL));

    if (strcmp(argv[1], "-help") == 0) {
        help();
        return OK;
    }
    args = init_args_config();
    if (args == NULL)
        return KO;
    if (fill_args_conf(args, argc, argv) == KO) {
        help();
        free_args_config(args);
        return KO;
    }
    display_args_config(args);
    resourse_list = generate_ressourse_list(args->width, args->height);
    display_char_tab_list(resourse_list);
    map_tile_t **map_tile = generate_map_tile(args->width, args->height);
    put_resource_on_map_tile(map_tile, resourse_list, args->width, args->height);
    free_map_tile(map_tile);
    clear_all(args, resourse_list);
    return OK;
}
