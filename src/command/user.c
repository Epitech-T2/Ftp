/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** user
*/

#include "../../include/myftp.h"

void user_cmd(client_t *client, char **tab)
{
    if (client->loggin == true) {
        dprintf(client->sock_client, ALR_LOGIN);
        return;
    }
    if (!tab[1]) {
        dprintf(client->sock_client, NEED_ACNT);
        return;
    }
    if (tab[1]) {
        client->user = strdup(tab[1]);
        dprintf(client->sock_client, NEED_PASS);
    }
}
