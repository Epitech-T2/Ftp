/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** port
*/

#include "../../include/myftp.h"

char *concat_ip(char **tab)
{
    char *str = malloc(sizeof(char) * (strlen(tab[0]) + strlen(tab[1]) +
        strlen(tab[2]) + strlen(tab[3]) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; i < 4; i++) {
        for (; tab[i][j] != '\0'; j++, k++)
            str[k] = tab[i][j];
        str[k] = '.';
        k++;
        j = 0;
    }
    str[k - 1] = '\0';
    return (str);
}

int init_port(client_t *client, char **tab)
{
    socklen_t pass_len = sizeof(client->passive);
    char *ip = concat_ip(tab);

    client->sock_passive = socket(PF_INET, SOCK_STREAM, 0);
    if (client->sock_passive == -1)
        return (84);
    client->passive.sin_family = AF_INET;
    client->passive.sin_port = htons(atoi(tab[4]) * 256 + atoi(tab[5]));
    client->passive.sin_addr.s_addr = inet_addr(ip);
    if (connect(client->sock_passive, (struct sockaddr *)&client->passive,
        pass_len) == -1) {
        close(client->sock_passive);
        return (84);
    }
    free_tab(tab);
    dprintf(client->sock_client, PORT_OK);
    free(ip);
    return (0);
}

int check_host(char **tab)
{
    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++)
            if (isdigit(tab[i][j]) != 0)
                return (0);
    return (1);
}

void set_port(client_t *client, char **tab)
{
    char **host = str_to_tab(tab[1], ",");

    if (host == NULL || check_host(host) == 1) {
        dprintf(client->sock_client, NOT_ENOUGH_ARG);
        return;
    }
    if (init_port(client, host) == 84)
        dprintf(client->sock_client, NOT_ENOUGH_ARG);
}

void port_cmd(client_t *client, char **tab)
{
    if (tab[1] == NULL) {
        dprintf(client->sock_client, NOT_ENOUGH_ARG);
        return;
    }
    set_port(client, tab);
}
