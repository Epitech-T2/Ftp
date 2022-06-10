/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** cdup
*/

#include "../../include/myftp.h"

void cdup_cmd(client_t *client, char **tab)
{
    if (chdir("..") == 0) {
        dprintf(client->sock_client, CHG_DIR);
        return;
    }
    dprintf(client->sock_client, INV_DIR);
}
