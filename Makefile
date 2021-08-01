# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 08:28:02 by graja             #+#    #+#              #
#    Updated: 2021/08/01 14:26:23 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= client
SNAME	= server

SRV		= server.c
CLI		= client.c
HLP		= helpers.c ft_itoa.c

RM			= rm -f
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror

all : $(SRV) $(CLI) $(HLP)
	$(CC) $(CFLAGS) $(CLI) $(HLP) -o client
	$(CC) $(CFLAGS) $(SRV) $(HLP) -o server

$(NAME) : $(CLI) $(HLP)
	$(CC) $(CFLAGS) $(CLI) $(HLP) -o client

$(SNAME): $(SRV) $(HLP)
	$(CC) $(CFLAGS) $(SRV) $(HLP) -o server

fclean : 
	$(RM) server client

clean : 
	$(RM) server client

re : fclean all

bonus : fclean all
