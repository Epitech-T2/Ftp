/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** get_line
*/

#include "../../include/myftp.h"

char **str_to_tab(char *str, char *tok)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * 2);
    char *token = strtok(str, tok);

    if (!str || !tab || !token)
        return (NULL);
    while (1) {
        tab[i] = strdup(token);
        i++;
        tab = realloc(tab, (sizeof(char *) * (i + 1)));
        token = strtok(NULL, tok);
        if (token == NULL) {
            tab[i] = token;
            break;
        }
    }
    free(token);
    return (tab);
}

static int get_line_next(client_t *client, char *line)
{
    char **tab = NULL;

    if (line) {
        tab = str_to_tab(line, "  \t\r\n");
        if (!tab || strcmp(tab[0], "") == 0) {
            dprintf(client->sock_client, NO_CMD);
            return (0);
        }
        return (select_command(client, tab));
    }
    return (84);
}

int get_line(client_t *client)
{
    char *line = NULL;
    FILE *fd;
    size_t n = 0;

    fd = fdopen(client->sock_client, "r");
    if (getline(&line, &n, fd) == -1) {
        fclose(fd);
        free(line);
        handle_error("Getline failed");
    }
    if (get_line_next(client, line) == 84)
        return (84);
    if (client->quit == true)
        return (close_client(client, 0));
    return (0);
}
