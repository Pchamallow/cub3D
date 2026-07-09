# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/07/09 15:52:20 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ================= VARIABLES ================= #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
MAKEFLAGS	+= --no-print-directory
DATE		:= $(shell date +"%y_%m_%d_%H-%M-%S")
BUILD_DIR	:= .cub3d

# Includes
INCLUDES	:=							\
				-Iincludes				\
		   		-Ilib/minilibx-linux/	\
				-Ilib/libft/			\

NAME		:= cub3d

# Colors
GREEN		:='\033[0;32m'
NC			:='\033[0m'

# Sources
SRCS		:=	srcs/main.c			\

OBJS		:= $(SRCS:src/%.c=$(BUILD_DIR)/%.o)



# ==================  LIBS  ================== #

# Minilibx
DIR_MLX		:= lib/minilibx-linux
MLX			:= lib/minilibx-linux/libmlx_Linux.a
FLAGS_MLX	:= -L./lib/minilibx-linux
ADD_LIB		:= -lmlx -lm -lX11 -lXext

# GNL
DIR_GNL	:= lib/get_next_line
GNL		:= lib/get_next_line/get_next_line.a

# Libft
DIR_LIB	:= lib/libft
LIBFT	:= lib/libft/libft.a



# ================= COMMANDS ================= #

all: $(MLX) $(LIBFT) $(NAME)
	@clear
	@echo $(GREEN)"💫 All compiled 💫\n"$(NC)

$(MLX):
	@$(MAKE) -C $(DIR_MLX) -s

$(LIBFT):
	@$(MAKE) -C $(DIR_LIB) -s

$(NAME): $(BUILD_DIR) $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(FLAGS_MLX) $(ADD_LIB) $(LIBFT) $(INCLUDES) -o $(NAME)
	@echo $(GREEN)"\n✨ cub3d build created. ✨\n"$(NC)

$(BUILD_DIR):
	@mkdir -p $@

# Compilation .c -> .o
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(DIR_MLX) clean -s
	@$(MAKE) -C $(DIR_LIB) clean -s
	@rm -rf $(BUILD_DIR)
	@echo $(GREEN)"cub3d build is clean. 🧹"$(NC)

fclean: clean
	@$(MAKE) -C $(DIR_LIB) fclean -s
	@rm -f $(NAME)
	@echo $(GREEN)"cub3d library is clean. 🧹"$(NC)

re: fclean 
	$(MAKE) all

.SILENT:
.PHONY: all clean fclean re