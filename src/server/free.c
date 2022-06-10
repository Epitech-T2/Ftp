/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** free
*/

#include "../../include/myftp.h"

int close_server(server_t *server, client_t *client, int out)
{
    for (int i = 0; i < MAX_CLIENTS ; i++) {
        if (client[i].sock_client != 0) {
            printf("Close socket: %d, username: %s\n", client[i].sock_client,
                client[i].user);
            close(client[i].sock_client);
        }
    }
    close(server->sock_server);
    free(client);
    free(server);
    return (out);
}

int close_client(client_t *client, int out)
{
    close(client->sock_client);
    client->sock_client = 0;
    free(client->user);
    free(client->password);
    return (out);
}

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i++])
        free(tab[i]);
    free(tab);
}
