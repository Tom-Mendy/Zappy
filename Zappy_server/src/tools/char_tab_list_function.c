/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** char_tab_list_function
*/

#include "zappy_server.h"

void free_char_tab_list(struct char_tab_head *head)
{
    char_tab_t *n1 = TAILQ_FIRST(head);
    char_tab_t *n2 = NULL;

    while (n1 != NULL) {
        n2 = n1;
        n1 = TAILQ_NEXT(n1, next);
        free(n2->str);
        free(n2);
    }
}

void display_char_tab_list(struct char_tab_head *head)
{
    char_tab_t *n1 = TAILQ_FIRST(head);

    TAILQ_FOREACH(n1, head, next) { printf("%s\n", n1->str); }
}
