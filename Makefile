# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 04:12:18 by oer-refa          #+#    #+#              #
#    Updated: 2024/04/18 14:28:30 by oer-refa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server2
NAME_2 = client

CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_itoa.c ft_putstr.c ft_strlen.c
SRCS =  $(SRC) server2.c
SRCC =  $(SRC) client.c
OBGS = $(SRCS:.c=.o)
OBGC = $(SRCC:.c=.o)
OBGSB = $(SRCSB:.c=.o)
OBGCB = $(SRCCB:.c=.o)
all : $(NAME) $(NAME_2)

$(NAME): $(OBGS)
	$(CC) $(CFLAGS) $(OBGS) -o $(NAME)

$(NAME_2): $(OBGC)
	$(CC) $(CFLAGS) $(OBGC) -o $(NAME_2)

bonus : $(NAME_3) $(NAME_4)

$(NAME_3): $(OBGSB)
	$(CC) $(CFLAGS) $(OBGSB) -o $(NAME_3)

$(NAME_4): $(OBGCB)
	$(CC) $(CFLAGS) $(OBGCB) -o $(NAME_4)
clean:
	rm -f $(OBGS) $(OBGC) $(OBGSB) $(OBGCB) 

fclean: clean
	rm -f $(NAME) $(NAME_2) $(NAME_3) $(NAME_4)  

re: fclean all