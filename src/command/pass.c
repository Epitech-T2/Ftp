/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** pass
*/

#include "../../include/myftp.h"

void pass_cmd(client_t *client, char **tab)
{
    if (client->loggin == true) {
        dprintf(client->sock_client, LOG_PRS);
        return;
    }
    if (client->user == NULL) {
        dprintf(client->sock_client, NEED_ACNT);
        return;
    }
    if ((strcasecmp("anonymous", client->user) == 0) &&
        (client->password == NULL)) {
        free(client->user);
        free(client->password);
        client->user = NULL;
        client->password = NULL;
        client->loggin = true;
        dprintf(client->sock_client, LOGED);
    }
}
