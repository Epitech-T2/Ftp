/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** dele
*/

#include "../../include/myftp.h"

void dele_cmd(client_t *client, char **tab)
{
    if (remove(tab[1]) == 0) {
        dprintf(client->sock_client, DELE);
        return;
    }
    dprintf(client->sock_client, BAD_FILE);
}
