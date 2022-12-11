CC = gcc
FLAGS = -Wall -Wextra -Werror

SERVER = $(CC) $(FLAGS) libft/libft.a server.c -o server
CLIENT = $(CC) $(FLAGS) libft/libft.a client.c -o client

NAME = libft/libft.a

LIBFT = make -C libft/
BONUS_SERVER = $(CC) $(FLAGS) libft/libft.a server_bonus.c -o server_bonus
BONUS_CLIENT = $(CC) $(FLAGS) libft/libft.a client_bonus.c -o client_bonus

all: $(NAME)

$(NAME): 
	$(LIBFT) 
	$(SERVER) 
	$(CLIENT)

clean:
	make fclean -C libft/ 

fclean: clean
	rm -rf server client server_bonus client_bonus

re: clean all

bonus: 
	$(LIBFT)
	$(BONUS_SERVER)
	$(BONUS_CLIENT)

.PHONY: all clean fclean re bonus
