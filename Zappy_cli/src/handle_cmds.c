/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** handle_cmds
*/

#include "myteams_cli.h"

void handle_help(char **info, int __attribute__((unused))socketfd)
{
    print_2d_array(info, 1);
}

void handle_login(char **info, int __attribute__((unused))socketfd)
{
}

void handle_logout(char **info, int socketfd)
{
    char *user_name = get_msg_up_to_char(info[1], *SPLIT_LINE, 0);
    char *user_uuid = get_msg_after_nb(info[1], (int)strlen(user_name));

    do_multiple_frees(user_uuid, user_name, NULL, NULL);
    free_2d_array(info);
    close(socketfd);
    exit(0);
}

void handle_users(char **info, int __attribute__((unused))socketfd)
{
    char *user_name = NULL;
    char *user_uuid = NULL;

    for (int i = 1; info[i] != NULL; i++) {
        user_uuid = get_msg_up_to_char(info[i], *SPLIT_LINE, 2);
        user_name = get_msg_after_nb(info[i], (int)strlen(user_uuid) + 2);
        do_multiple_frees(user_uuid, user_name, NULL, NULL);
    }
}

void handle_user(char **info, int __attribute__((unused))socketfd)
{
}
