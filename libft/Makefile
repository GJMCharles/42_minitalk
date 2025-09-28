# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 11:55:25 by grcharle          #+#    #+#              #
#    Updated: 2025/08/28 06:53:08 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

RM := rm -frv
NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDE := -I.

AR := ar
AR_FLAGS := -rs

SOURCES_MANDATORY := \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c

SOURCES_BONUS := \
ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

SOURCES_EXTRA :=

OBJECTS := $(patsubst %.c,%.o,$(SOURCES_MANDATORY) $(SOURCES_BONUS) $(SOURCES_EXTRA))

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(AR_FLAGS) $@ $^

clean:
	@$(RM) $(patsubst %.c,%.o,$(SOURCES_MANDATORY) $(SOURCES_BONUS) $(SOURCES_EXTRA))

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
