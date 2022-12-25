# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 03:41:10 by drtaili           #+#    #+#              #
#    Updated: 2022/12/25 04:50:43 by drtaili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c
SERVER = server.c

CLIENT_BONUS = client_bonus.c
SERVER_BONUS = server_bonus.c

OBJS_C = $(CLIENT:.c=.o)
OBJS_S = $(SERVER:.c=.o)

OBJS_C_b = $(CLIENT_BONUS:.c=.o)
OBJS_S_b = $(SERVER_BONUS:.c=.o)

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror



all: client server client_bonus server_bonus

client: $(OBJS_C)
	$(CC) $(FLAGS) $(OBJS_C) -o client

server: $(OBJS_S)
	$(CC) $(FLAGS) $(OBJS_S) -o server

client_bonus: $(OBJS_C_b)
	$(CC) $(FLAGS) $(OBJS_C_b) -o client_bonus

server_bonus: $(OBJS_S_b)
	$(CC) $(FLAGS) $(OBJS_S_b) -o server_bonus

%.o : %.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_C) $(OBJS_S) $(OBJS_C_b) $(OBJS_S_b)

fclean: clean
	$(RM) client server client_bonus server_bonus

re: fclean client server client_bonus server_bonus 

.PHONY = all clean fclean re