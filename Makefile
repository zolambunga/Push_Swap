# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 01:19:59 by zombunga          #+#    #+#              #
#    Updated: 2024/10/25 02:16:09 by zombunga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable
NAME	= push_swap

# compilator and flags
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

# source arquives and object directory
SRCS	= ./src/utils/sort_big_utils.c	\
		  ./src/utils/utils.c			\
		  ./src/utils/ft_sorters.c		\
		  ./src/utils/utils3.c			\
		  ./src/utils/error_handling.c	\
		  ./src/utils/verify_args.c		\
		  ./src/utils/movers.c			\
		  ./src/utils/utils2.c			\
		  ./src/utils/ft_free.c			\
		  ./src/algorithm/set_target.c	\
		  ./src/algorithm/update_index.c\
		  ./src/algorithm/push_cost.c	\
		  ./src/operations/push.c		\
		  ./src/operations/swap.c		\
		  ./src/operations/rotate.c		\
		  ./src/operations/rev_rotate.c	\
		  ./src/main.c

# compiled objects directory
OBJ_DIR	= objs
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# libft path
LIBFT_DIR	= ./includes/libft
LIBFT		= $(LIBFT_DIR)/libft.a

# rule for the executable
all: $(NAME)

# rule to compile the executable
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Executable $(NAME) created."

# rule to compile the objects
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< into $@."

# rule to compile the libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# clean objects
clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "Objects cleaned."

# clean everything, including the executable
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Executable $(NAME) removed."

# ru to recompile everything
re: fclean all

.PHONY: all clean fclean re