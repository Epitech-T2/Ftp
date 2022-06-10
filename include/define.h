/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myftp-romanie.de-meyer
** File description:
** define
*/

#ifndef DEFINE_H_
    #define DEFINE_H_

    #define handle_error(msg) ({ perror(msg); exit(84); })
    #define MAX_CLIENTS 10

    #define HELP \
    "\t 214 Help message.\n \
        USER <SP> <username> <CRLF>   : Specify user for authentication\n \
        PASS <SP> <password> <CRLF>   : Specify password for authentication\n \
        CWD  <SP> <pathname> <CRLF>   : Change working directory\n \
        CDUP <CRLF>                   : Change working directory to parent \
directory\n \
        QUIT <CRLF>                   : Disconnection\n \
        DELE <SP> <pathname> <CRLF>   : Delete file on the server\n \
        PWD  <CRLF>                   : Print working directory\n \
        PASV <CRLF>                   : Enable 'passive' mode for data \
transfer\n \
        PORT <SP> <host-port> <CRLF>  : Enable 'active' mode for data \
transfer\n \
        HELP [<SP> <string>] <CRLF>   : List available commands\n \
        NOOP <CRLF>                   : Do nothing\n \
        (the following are commands using data transfer )\n \
        RETR <SP> <pathname> <CRLF>   : Download file from server to client\n \
        STOR <SP> <pathname> <CRLF>   : Upload file from client to server\n \
        LIST [<SP> <pathname>] <CRLF> : List files in the current working \
directory\n"

    #define PORT_OK "200 PORT command success.\n"
    #define CMD_OK "200 Command okay.\n"
    #define CHG_DIR "200 Change working directory to parent directory.\n"
    #define LOGIN "220 Connection.\n"
    #define QUIT "221 Service closing control connection.\n"
    #define LOG_PRS "230 User logged in, proceed.\n"
    #define LOGED "230 Login successful.\n"
    #define CHG_WORK_DIR "250 Change working directory.\n"
    #define DELE "250 File successfully removed.\n"
    #define NEED_PASS "331 User name okay, need password.\n"
    #define NEED_ACNT "332 Need username first for login.\n"
    #define NO_CMD "500 Command not implemented.\n"
    #define NOT_ENOUGH_ARG "500 Not enough arguments.\n"
    #define NOT_LOGIN "530 Login Authentication failed.\n"
    #define ALR_LOGIN "530 Already login\n"
    #define INV_DIR "550 Invalid directory.\n"
    #define BAD_FILE "550 Bad file.\n"

#endif /* !DEFINE_H_ */
