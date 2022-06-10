/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** pwd
*/

#include "../../include/myftp.h"

void pwd_cmd(client_t *client, char **tab)
{
    char *buf = NULL;

    buf = malloc(sizeof(char) * 150);
    getcwd(buf, 150);
    dprintf(client->sock_client, "257 %s\n", buf);
    free(buf);
}
