/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** handle_list_cmds
*/

#include "myteams_cli.h"

// printf("\n"); //////////////////////////////////////////////
// print_2d_array(info, 0); //////////////////////////////////////////////
// printf("\n"); //////////////////////////////////////////////
void list_teams(char **info, int __attribute__((unused)) add)
{
    char *team_uuid = NULL;
    char *team_name = NULL;
    char *team_desc = NULL;

    for (int i = 2; info[i] != NULL; i++) {
        team_uuid = get_msg_up_to_char(info[i], *SPLIT_LINE, 0);
        team_name = get_msg_up_to_char(info[i], *SPLIT_LINE,
        (int)strlen(team_uuid) + 1);
        team_desc = get_msg_after_nb(info[i],
        (int)strlen(team_uuid) + (int)strlen(team_name) + 2);
        do_multiple_frees(team_uuid, team_name, team_desc, NULL);
    }
}

void list_channels(char **info, int __attribute__((unused)) add)
{
    char *channel_uuid = NULL;
    char *channel_name = NULL;
    char *channel_desc = NULL;

    for (int i = 2; info[i] != NULL; i++) {
        channel_uuid = get_msg_up_to_char(info[i], *SPLIT_LINE, 0);
        channel_name = get_msg_up_to_char(info[i], *SPLIT_LINE,
        (int)strlen(channel_uuid) + 1);
        channel_desc = get_msg_after_nb(info[i],
        (int)strlen(channel_uuid) + (int)strlen(channel_name) + 2);
        do_multiple_frees(channel_uuid, channel_name, channel_desc, NULL);
    }
}

void list_threads(char **info, int add)
{
    char *th_uu = NULL;
    char *u_uu = NULL;
    char *th_ts = NULL;
    char *th_t = NULL;
    char *th_b = NULL;

    for (int i = 2; info[i] != NULL; i++) {
        add = 0;
        th_uu = get_msg_up_to_char(info[i], *SPLIT_LINE, 0);
        add = (int)strlen(th_uu) + 1;
        u_uu = get_msg_up_to_char(info[i], *SPLIT_LINE, add);
        add += (int)strlen(u_uu) + 1;
        th_ts = get_msg_up_to_char(info[i], *SPLIT_LINE, add);
        add += (int)strlen(th_ts) + 1;
        th_t = get_msg_up_to_char(info[i], *SPLIT_LINE, add);
        th_b = get_msg_after_nb(info[i], add + (int)strlen(th_t) + 1);
        do_multiple_frees(th_uu, u_uu, th_ts, th_t);
        free(th_b);
    }
}

void list_replies(char **info, int __attribute__((unused)) add)
{
    char *thread_uuid = NULL;
    char *user_uuid = NULL;
    char *reply_timestamp = NULL;
    char *reply_body = NULL;

    for (int i = 2; info[i] != NULL; i++) {
        thread_uuid = get_msg_up_to_char(info[i], *SPLIT_LINE, 0);
        user_uuid = get_msg_up_to_char(info[i], *SPLIT_LINE,
        (int)strlen(thread_uuid) + 1);
        reply_timestamp = get_msg_up_to_char(info[i], *SPLIT_LINE,
        (int)strlen(thread_uuid) + (int)strlen(user_uuid) + 2);
        reply_body = get_msg_after_nb(info[i], (int)strlen(thread_uuid)
        + (int)strlen(user_uuid) + (int)strlen(reply_timestamp) + 3);
        do_multiple_frees(thread_uuid, user_uuid, reply_timestamp,
        reply_body);
    }
}
