/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** pasv
*/

#include "../../include/myftp.h"

static int set_passive(client_t *client, socklen_t pass_len)
{
    if (bind(client->sock_passive, (struct sockaddr *)&client->passive,
        sizeof(client->passive)) == -1){
        close(client->sock_passive);
        handle_error("Bind failed");
    }
    if (listen(client->sock_passive, 1024) == -1){
        close(client->sock_passive);
        handle_error("Listen failed");
    }
    if (getsockname(client->sock_passive, (struct sockaddr *)&client->passive,
        &pass_len) == -1)
        return (84);
    client->passive_port = ntohs(client->passive.sin_port);
    return (0);
}

static int init_passive_mode(client_t *client)
{
    struct protoent *protocol;
    socklen_t pass_len = sizeof(client->passive);

    protocol = getprotobyname("tcp");
    if (protocol == NULL)
        return (84);
    client->sock_passive = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
    if (client->sock_passive == -1)
        return (84);
    memset(&client->passive, 0, pass_len);
    client->passive.sin_family = AF_INET;
    client->passive.sin_port = htons(0);
    client->passive.sin_addr.s_addr = INADDR_ANY;
    if (set_passive(client, pass_len) == 84)
        return (84);
    return (0);
}

static void passive_send(client_t *client)
{
    char **ip = NULL;

    ip = str_to_tab(client->ip, ".");
    dprintf(client->sock_client, "227 Entering Passive Mode (");
    for (int i = 0; ip[i]; i++) {
        dprintf(client->sock_client, "%s,", ip[i]);
    }
    dprintf(client->sock_client, "%d,%d).\n", client->passive_port / 256,
        client->passive_port % 256);
    free_tab(ip);
}

void pasv_cmd(client_t *client, char **tab)
{
    if (init_passive_mode(client) == 84) {
        dprintf(client->sock_client, "500 Error pasv.\n");
        return;
    }
    passive_send(client);
}
