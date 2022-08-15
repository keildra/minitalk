CC = gcc

CFLAGS = -Wall -Werror -Wextra

CLIENT = client

SERVER = server

NAME = ignore

all: $(CLIENT) $(SERVER)

.c.o:
	$(CC) -c $< -o $@

$(NAME): all 

$(CLIENT): client.c minitalk_utils.c
	$(CC) $(CFLAGS) client.c minitalk_utils.c -o client
$(SERVER): server.c minitalk_utils.c
	$(CC) $(CFLAGS) server.c minitalk_utils.c -o server

bonus: all

clean:
	rm -rf client server
fclean: clean

re: clean all

.PHONY: all clean fclean re bonus