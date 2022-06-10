/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** select_command
*/

#include "../../include/myftp.h"

int select_command(client_t *client, char **tab)
{
    const char *command[15] = {"USER", "PASS", "CWD", "CDUP", "QUIT", "DELE",
        "PWD", "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST", NULL};
    void (*func[14])(client_t *client, char **tab) = {&user_cmd, &pass_cmd,
        &cwd_cmd, &cdup_cmd, &quit_cmd, &dele_cmd, &pwd_cmd, &pasv_cmd,
        &port_cmd, &help_cmd, &noop_cmd, &retr_cmd, &stor_cmd, &list_cmd};
    if (!(strcasecmp(tab[0], "USER") == 0 || strcasecmp(tab[0], "HELP") == 0 ||
        strcasecmp(tab[0], "QUIT") || strcasecmp(tab[0], "PASS") == 0) &&
        client->loggin == false) {
        dprintf(client->sock_client, NOT_LOGIN);
        return (0);
    }
    for (int i = 0; command[i] != NULL; i++) {
        if (strcasecmp(tab[0], command[i]) == 0) {
            (*func[i])(client, tab);
            return (0);
        }
    }
    dprintf(client->sock_client, NO_CMD);
    return (0);
}
