NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
RM = rm -rf
LIBC = ar rcs
SRCS = srcs/ft_printf.c srcs/ft_prt_hex_low_len.c srcs/ft_prt_hex_upp_len.c srcs/ft_prt_num_len.c \
       srcs/ft_prt_ptr_len.c srcs/ft_prt_str_len.c srcs/ft_prt_unsi_len.c
OBJS = $(SRCS:.c=.o)
GREEN = \033[0;32m
NC = \033[0m
ORANGE = \033[0;33m
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft
	@cp libft/libft.a $(NAME)
	@$(LIBC) $(NAME) $(OBJS)
	@echo "$(GREEN)libprintf.a created!$(NC)"
clean:
	@$(MAKE) clean -s -C ./libft
	@$(RM) $(OBJS)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(ORANGE) -Compiling $(patsubst srcs/%,%,$<)     \t|\t   ft_printf$(NC)"
fclean: clean
	@$(MAKE) fclean -s -C ./libft
	@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
