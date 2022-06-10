/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** server
*/

#include "../../include/myftp.h"

static void init_client(client_t *client)
{
    client->sock_client = 0;
    client->password = NULL;
    client->user = NULL;
    client->quit = false;
    client->loggin = false;
    client->sock_passive = 0;
    client->passive_port = 0;
}

static void new_connection(server_t *server, client_t *client)
{
    int new_sock_client = 0;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    memset(&client_addr, 0, client_len);
    new_sock_client = accept(server->sock_server,
        (struct sockaddr *)&client_addr, &client_len);
    if (new_sock_client == -1)
        handle_error("Failed accept");
    dprintf(new_sock_client, LOGIN);
    printf("New Connection\n");
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (client[i].sock_client == 0) {
            client[i].sock_client = new_sock_client;
            break;
        }
    }
}

static int fd_isset(server_t *server, client_t *client)
{
    if (FD_ISSET(server->sock_server, &server->rset))
        new_connection(server, client);
    for (int i = 0; i < MAX_CLIENTS; i++)
        if (FD_ISSET(client[i].sock_client, &server->rset))
            return (get_line(&client[i]));
    return (0);
}

static void build_fd_set(server_t *server, client_t *client)
{
    FD_ZERO(&server->rset);
    FD_SET(server->sock_server, &server->rset);
    server->high_sock = server->sock_server;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client[i].sock_client)
            FD_SET(client[i].sock_client, &server->rset);
        if (client[i].sock_client > server->high_sock)
            server->high_sock = client[i].sock_client;
    }
}

int select_func(server_t *server)
{
    client_t *client = malloc(sizeof(client_t) * MAX_CLIENTS);
    int nready = 0;

    errno = 0;
    if (client == NULL)
        handle_error("Bad Malloc");
    signal(SIGINT, handler_signal);
    for (int i = 0; i < MAX_CLIENTS; i++)
        init_client(&(client[i]));
    while (run) {
        build_fd_set(server, client);
        nready = select(server->high_sock + 1, &server->rset, NULL, NULL, NULL);
        if (nready == -1 && errno == EINTR)
            continue;
        else if (nready == -1)
            return (close_server(server, client, 84));
        if (fd_isset(server, client) == 84)
            return (close_server(server, client, 84));
    }
    return (close_server(server, client, 0));
}
