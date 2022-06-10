/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** noop
*/

#include "../../include/myftp.h"

void noop_cmd(client_t *client, char **tab)
{
    dprintf(client->sock_client, CMD_OK);
}
