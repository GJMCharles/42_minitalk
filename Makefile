# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/17 14:46:43 by grcharle          #+#    #+#              #
#    Updated: 2025/08/25 13:14:49 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT := client
NAME_SERVER := server

CC := cc

FLAGS := -Wall -Wextra -Werror

SOURCES_SERVER := \
	minitalk_server.c

SOURCES_CLIENT := \
	minitalk_client.c

OBJECTS_SERVER := $(patsubst %.c,%.o,$(SOURCES_SERVER))
OBJECTS_CLIENT := $(patsubst %.c,%.o,$(SOURCES_CLIENT))

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME_SERVER): $(OBJECTS_SERVER)
	@make -C libft all
	@make -C ft_printf all
	$(CC) $(FLAGS) $^ -L ./ft_printf -lftprintf -o $@

$(NAME_CLIENT): $(OBJECT_CLIENT)
	@make -C libft all

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus:

clean:
	@make -C libft clean
	@make -C ft_printf clean
	@$(RM) -frv $(OBJECTS_SERVER)
	@$(RM) -frv $(OBJECTS_CLIENT)

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@$(RM) -frv $(NAME_SERVER)
	@$(RM) -frv $(NAME_CLIENT)


re: fclean all

.PHONY: all clean fclean re
