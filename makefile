NAME	=	Minitalk
CLIENT	=	client
SERVER	=	server
SRC_C	=	client.c bit_change.c strlen.c
SRC_S	=	server.c itoa.c
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

GREEN		=	\033[0;32m
SUCCESS	=	$(GREEN)[SUCCESS]

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): 
	@ $(CC) $(FLAGS) $(SRC_S) -o $(SERVER)
	@printf "$(SUCCESS) server ready.\n"
	

$(CLIENT): 
	@ $(CC) $(FLAGS) $(SRC_C) -o $(CLIENT)
	@printf "$(SUCCESS) client ready.\n"



clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "client removed.\n"
	@printf "server removed.\n"

re: clean all

.PHONY: all clean re