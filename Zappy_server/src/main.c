/*
** EPITECH PROJECT, 2024
** my_scripts
** File description:
** main
*/

#include "myteams_server.h"
#include <unistd.h>

typedef struct args_config_s {
    int port;
    int width;
    int height;
    int clientsNb;
    float freq;
    char **names;
} args_config_t;

void help(void)
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

args_config_t *init_args_config(void)
{
    args_config_t *args = calloc(sizeof(args_config_t), 1);

    args->port = 0;
    args->width = 0;
    args->height = 0;
    args->clientsNb = 0;
    args->freq = 0.0f;
    args->names = calloc(sizeof(char *), 100);
    return args;
}

int check_args(args_config_t *args)
{
    if (args->port <= 0 || args->width <= 0 || args->height <= 0 ||
        args->clientsNb == 0 || args->freq == 0.0f) {
        help();
        return KO;
    }
    return OK;
}

static int fill_args_conf_three(args_config_t *args, int argc, char **argv,
    int opt)
{
    switch (opt) {
    case 'n':
        for (int i = optind - 1; i < argc && *argv[i] != '-'; i++) {
            args->names[i - optind + 1] =
                calloc(sizeof(char), strlen(argv[i]) + 1);
            strcpy(args->names[i - optind + 1], argv[i]);
        }
        break;
    case 'c':
        args->clientsNb = atoi(optarg);
        break;
    case 'f':
        args->freq = atof(optarg);
        break;
    default:
        help();
        return KO;
    }
    return OK;
}

static int fill_args_conf_sec(args_config_t *args, int argc, char **argv,
    int opt)
{
    switch (opt) {
    case 'p':
        args->port = atoi(optarg);
        break;
    case 'x':
        args->width = atoi(optarg);
        break;
    case 'y':
        args->height = atoi(optarg);
        break;
    default:
        if (fill_args_conf_three(args, argc, argv, opt) == KO) {
            return KO;
        }
    }
}

int fill_args_conf(args_config_t *args, int argc, char **argv)
{
    int opt = getopt(argc, argv, "p:x:y:n:c:f:");

    while (opt != -1) {
        fill_args_conf_sec(args, argc, argv, opt);
        opt = getopt(argc, argv, "p:x:y:n:c:f:");
    }
    if (check_args(args) == KO)
        return KO;
    return OK;
}

int display_args_config(args_config_t *args)
{
    printf("Port: %d\n", args->port);
    printf("Width: %d\n", args->width);
    printf("Height: %d\n", args->height);
    printf("Team Names:\n");
    for (int i = 0; args->names[i] != NULL; i += 1) {
        printf("%s\n", args->names[i]);
        free(args->names[i]);
    }
    free(args->names);
    printf("Clients Number: %d\n", args->clientsNb);
    printf("Frequency: %.2f\n", args->freq);
    return OK;
}

int main(int argc, char **argv)
{
    args_config_t *args = NULL;

    if (strcmp(argv[1], "-help") == 0) {
        help();
        return OK;
    }
    args_config_t *args = init_args_config();
    if (fill_args_conf(args, argc, argv) == KO) {
        return KO;
    }
    display_args_config(args);
    return (0);
}
