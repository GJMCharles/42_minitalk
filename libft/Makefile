# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 11:55:25 by grcharle          #+#    #+#              #
#    Updated: 2025/08/23 17:03:04 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

NAME := libft.a
NAME_MANDATORY := $(NAME)
NAME_BONUS := $(NAME)

CFLAGS += -Wall -Wextra -Werror

SOURCES_MANDATORY := \
./ft_atoi.c \
./ft_bzero.c \
./ft_calloc.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_itoa.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_putchar_fd.c \
./ft_putendl_fd.c \
./ft_putnbr_fd.c \
./ft_putstr_fd.c \
./ft_split.c \
./ft_strchr.c \
./ft_strdup.c \
./ft_striteri.c \
./ft_strjoin.c \
./ft_strlcat.c \
./ft_strlcpy.c \
./ft_strlen.c \
./ft_strmapi.c \
./ft_strncmp.c \
./ft_strnstr.c \
./ft_strrchr.c \
./ft_strtrim.c \
./ft_substr.c \
./ft_tolower.c \
./ft_toupper.c

SOURCES_BONUS := \
./ft_lstnew.c \
./ft_lstadd_front.c \
./ft_lstsize.c \
./ft_lstlast.c \
./ft_lstadd_back.c \
./ft_lstdelone.c \
./ft_lstclear.c \
./ft_lstiter.c \
./ft_lstmap.c

OBJECTS_MANDATORY := $(patsubst %.c,%.o,$(SOURCES_MANDATORY))

OBJECTS_BONUS := $(patsubst %.c,%.o,$(SOURCES_BONUS))

INCLUDE := -I./.

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME_MANDATORY): $(OBJECTS_MANDATORY)
	ar rcs -o $@ $^

$(NAME_BONUS): $(OBJECTS_BONUS)
	ar rcs -o $@ $^

all: $(NAME_MANDATORY) $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	@$(RM) -frv $(OBJECTS_MANDATORY) $(OBJECTS_BONUS)

fclean:	clean
	@$(RM) -v $(NAME)

re: fclean all

.PHONY: all clean fclean re
