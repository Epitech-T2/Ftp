/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** main
*/

#include "../include/myftp.h"

static server_t *init_next(server_t *server, char *path)
{
    memset(&server->address, 0, server->lenght);
    server->address.sin_family = AF_INET;
    server->address.sin_port = htons(server->port);
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->high_sock = 0;
    server->path = path;
    return (server);
}

static server_t *init_struct_server(char *port, char *path)
{
    server_t *server = (server_t *)malloc(sizeof(server_t));

    if (server == NULL)
        return (NULL);
    server->port = atoi(port);
    server->lenght = sizeof(server->address);
    server->sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock_server == -1)
        return (NULL);
    init_next(server, path);
    return (server);
}

static void set_server(server_t *server)
{
    if (chdir(server->path) == -1)
        handle_error("Bad path\n");
    if (bind(server->sock_server, (struct sockaddr *)&server->address,
        server->lenght) == -1){
        close(server->sock_server);
        handle_error("Bind failed");
    }
    if (listen(server->sock_server, 1024) == -1) {
        close(server->sock_server);
        handle_error("Listen failed");
    }
}

static int loop(server_t *server)
{
    set_server(server);
    if (select_func(server) == 84)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    server_t *server = init_struct_server(av[1], av[2]);

    if (ac == 2 && (strcmp(av[1], "-help") == 0)) {
        print_help();
        return (0);
    }
    if (ac != 3 || server == NULL)
        return (84);
    if (loop(server) == 84)
        return (84);
    return (0);
}
