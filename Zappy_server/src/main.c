/*
** EPITECH PROJECT, 2024
** my_scripts
** File description:
** main
*/

#include "zappy_server.h"

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
    clear_all(args, resourse_list);
    return OK;
}
