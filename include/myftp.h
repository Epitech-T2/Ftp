/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <netdb.h>
    #include <ctype.h>
    #include <errno.h>
    #include <signal.h>

    #include "define.h"

    static volatile sig_atomic_t run = 1;

    static inline void handler_signal(__attribute__((unused)) int signal)
    {
        run = 0;
    }

    typedef struct server {
        struct sockaddr_in address;
        socklen_t lenght;
        int sock_server;
        int high_sock;
        int port;
        char *path;
        fd_set rset;
    } server_t;

    typedef struct client {
        struct sockaddr_in client;
        int sock_client;
        char *user;
        char *password;
        bool quit;
        bool loggin;
        char *ip;
        struct sockaddr_in passive;
        int sock_passive;
        int passive_port;
    } client_t;

    int close_client(client_t *client, int out);
    int close_server(server_t *server, client_t *client, int out);
    int select_func(server_t *server);
    void print_help(void);
    int select_command(client_t *client, char **tab);
    char **str_to_tab(char *str, char *tok);
    int get_line(client_t *client);
    void free_client(client_t *client);
    void free_tab(char **tab);

// -------------------- Commands ------------------------

    void cdup_cmd(client_t *client, char **tab __attribute__((unused)));
    void cwd_cmd(client_t *client, char **tab);
    void dele_cmd(client_t *client, char **tab);
    void help_cmd(client_t *client, char **tab __attribute__((unused)));
    void list_cmd(client_t *client __attribute__((unused)),
        __attribute__((unused)) char **tab);
    void noop_cmd(client_t *client, __attribute__((unused)) char **tab);
    void pass_cmd(client_t *client, __attribute__((unused)) char **tab);
    void pasv_cmd(client_t *client, __attribute__((unused)) char **tab);
    void port_cmd(client_t *client, char **tab);
    void pwd_cmd(client_t *client, __attribute__((unused)) char **tab);
    void quit_cmd(client_t *client, char **tab);
    void retr_cmd(__attribute__((unused)) client_t *client,
        __attribute__((unused)) char **tab);
    void user_cmd(client_t *client, char **tab);
    void stor_cmd(__attribute__((unused)) client_t *client,
        __attribute__((unused)) char **tab);

#endif /* !MYFTP_H_ */
