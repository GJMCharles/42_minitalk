# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 22:11:15 by grcharle          #+#    #+#              #
#    Updated: 2025/09/29 22:18:26 by gjmcharles       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .DEFAULT_GOAL := all

NAME := client server

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKEFLAGS := --no-print-directory

LIBFT_SRC := ./libft
FTPRINTF_SRC := ./ftprintf

LDFLAGS := -I. -I$(FTPRINTF_SRC) -I$(LIBFT_SRC)
LDLIBS := \
	-L$(LIBFT_SRC) -lft \
	-L$(FTPRINTF_SRC) -lftprintf

SOURCES := client.c server.c utils.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

all: LIBS client server

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

LIBS:
	@make -C $(LIBFT_SRC) all
	@make -C $(FTPRINTF_SRC) all

client:
	$(CC) $(CFLAGS) $(LDFLAGS) utils.o client.o -o client $(LDLIBS)

server:
	$(CC) $(CFLAGS) $(LDFLAGS) utils.o server.o -o server $(LDLIBS)

$(NAME): $(OBJECTS)

clean:
	@make -C $(LIBFT_SRC) clean
	@make -C $(FTPRINTF_SRC) clean
	@$(RM) $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_SRC) fclean
	@make -C $(FTPRINTF_SRC) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
