##
## EPITECH PROJECT, 2022
## B-NWP-400-STG-4-1-myftp-romanie.de-meyer
## File description:
## Makefile
##

SRC =	src/main.c \
		src/print.c \
		src/server/server.c \
		src/command/select_command.c \
		src/command/user.c \
		src/command/pass.c \
		src/command/cwd.c \
		src/command/pwd.c \
		src/command/noop.c \
		src/command/dele.c \
		src/command/quit.c \
		src/command/help.c \
		src/command/cdup.c \
		src/command/pasv.c \
		src/command/port.c \
		src/command/list.c \
		src/command/retr.c \
		src/command/stor.c \
		src/server/get_line.c \
		src/server/free.c \

OBJ = 	$(SRC:.c=.o)

NAME = 	myftp

CC = gcc

CFLAGS = -g -Wall

all: 	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
