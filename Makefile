# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 01:19:08 by grcharle          #+#    #+#              #
#    Updated: 2025/09/29 01:19:12 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

LIBFT_SRC := ./libft

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -I. -L$(LIBFT_SRC) -lft

NAME := server client

OBJECTS_SERVER := $(patsubst %.c,%.o,server.c)
OBJECTS_CLIENT := $(patsubst %.c,%.o,client.c)

all: LIBFT $(NAME)

LIBFT:
	@make -C $(LIBFT_SRC) all

clean:
	@make -C $(LIBFT_SRC) clean
	@$(RM) $(OBJECTS_SERVER) $(OBJECTS_CLIENT)

fclean:
	@make -C $(LIBFT_SRC) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
