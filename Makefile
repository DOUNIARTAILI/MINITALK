# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 03:41:10 by drtaili           #+#    #+#              #
#    Updated: 2022/12/24 04:14:44 by drtaili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c
SERVER = server.c

OBJS_C = $(CLIENT:.c=.o)
OBJS_S = $(SERVER:.c=.o)

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror



all: client server

client: $(OBJS_C)
	$(cc) $(FLAGS) $(OBJS_C) -o client

server: $(OBJS_S)
	$(cc) $(FLAGS) $(OBJS_S) -o server

%.o : %.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_C) $(OBJS_S)

fclean: clean
	$(RM) client server

re: fclean client server 

.PHONY = all clean fclean re