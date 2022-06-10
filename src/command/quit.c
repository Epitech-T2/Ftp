/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** quit
*/

#include "../../include/myftp.h"

void quit_cmd(client_t *client, char **tab)
{
    dprintf(client->sock_client, QUIT);
    client->quit = true;
}
