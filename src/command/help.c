/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** help
*/

#include "../../include/myftp.h"

void help_cmd(client_t *client, char **tab)
{
    dprintf(client->sock_client, HELP);
}
