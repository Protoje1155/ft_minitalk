# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoster <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 15:14:52 by mkoster           #+#    #+#              #
#    Updated: 2024/05/27 13:35:46 by mkoster          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra -I.includes/

SRCS_S = $(addprefix srcs/, server.c)
OBJ_S = $(SRCS_S:.c=.o)

SRCS_C = $(addprefix srcs/, client.c)
OBJ_C = $(SRCS_C:.c=.o)

SRCS_H = $(addprefix srcs/, helper_functions.c more_helper_functions.c)
OBJ_H = $(SRCS_H:.c=.o)

NAME_S = server
NAME_C = client
LIBS = libs
CC = cc

GREEN = \033[0;32m
NC = \033[0m
ORANGE = \033[0;33m

all: $(NAME_S) $(NAME_C)

bonus: $(NAME_S) $(NAME_C)
	@echo "$(GREEN)Bonus created!$(NC)"

$(LIBS):
	@$(MAKE) -s -C ./printf

$(NAME_S): $(OBJ_S) $(LIBS) $(OBJ_H)
	@$(CC) $(CFLAGS) -o $(NAME_S) $(OBJ_S) $(OBJ_H) -L./printf -lftprintf
	@echo "$(GREEN)Server created!$(NC)"

$(NAME_C): $(OBJ_C) $(LIBS) $(OBJ_H)
	@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJ_C) $(OBJ_H) -L./printf -lftprintf
	@echo "$(GREEN)Client created!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o  $@
	@echo "$(ORANGE) -Compiling $(patsubst srcs/%,%,$<)   \t\t|\t   minitalk$(NC)"
clean:
	@$(MAKE) clean -s -C ./printf
	@rm -rf $(OBJ_S) $(OBJ_C) $(OBJ_H)
	@echo "$(GREEN)clean done for minitalk!$(NC)"

fclean: clean
	@$(MAKE) fclean -s -C ./printf
	@rm -rf $(NAME_S) $(NAME_C)
	@echo "$(GREEN)fclean done for minitalk!$(NC)"

re: fclean all 

.PHONY: all re fclean clean bonus
