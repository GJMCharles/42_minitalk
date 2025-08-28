# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 22:56:16 by grcharle          #+#    #+#              #
#    Updated: 2025/08/23 17:17:00 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := libftprintf.a

LIBFT := ../libft

LIBFT_OBJ := \
	ft_putchar_fd.o \
	ft_strdup.o \
	ft_strlen.o \
	ft_putstr_fd.o \
	ft_putnbr_fd.o \
	ft_strlcpy.o \
	ft_strjoin.o \
	ft_calloc.o \
	ft_memcpy.o \
	ft_bzero.o \
	ft_memset.o \
	ft_itoa.o

CFLAGS := -Wall -Wextra -Werror

SOURCES := \
	ft_printf.c \
	ft_printf_string.c \
	ft_printf_integer.c \
	ft_printf_hex.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

AR := ar

RM := rm

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@make -C $(LIBFT) all
	@$(AR) -x $(LIBFT)/libft.a $(LIBFT_OBJ)
	@$(AR) -rcs $@ $^ $(LIBFT_OBJ)
	ranlib $@

clean :
	@make -C $(LIBFT) clean
	@$(RM) -frv $(OBJECTS) $(LIBFT_OBJ)

fclean : clean
	@make -C $(LIBFT) fclean
	@$(RM) -frv $(NAME)
	@$(RM) -frv *.gch
	@$(RM) -frv a.out

re : fclean all

.PHONY: all clean fclean re
