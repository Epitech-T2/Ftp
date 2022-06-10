/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** cwd
*/

#include "../../include/myftp.h"

void cwd_cmd(client_t *client, char **tab)
{
    if (chdir(tab[1]) == 0) {
        dprintf(client->sock_client, CHG_WORK_DIR);
        return;
    }
    dprintf(client->sock_client, INV_DIR);
}
