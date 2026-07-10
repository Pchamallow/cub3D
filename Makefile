# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/07/10 17:24:35 by nbaudoin         ###   ########.fr        #
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
				-Ilib/get_next_line/

NAME		:= cub3d

# Colors
GREEN		:='\033[0;32m'
NC			:='\033[0m'

# Sources

ERROR_DIR	= srcs/error
ERROR_SRCS	= $(ERROR_DIR)/error.c

PARSER_DIR	= srcs/parser
PARSER_SRCS	= $(PARSER_DIR)/args.c $(PARSER_DIR)/map.c

# GNL (pas de Makefile : compilé avec les sources du projet)
DIR_GNL		= lib/get_next_line
GNL_SRCS	= $(DIR_GNL)/get_next_line.c $(DIR_GNL)/get_next_line_utils.c

SRCS		:= srcs/main.c $(PARSER_SRCS) $(ERROR_SRCS) $(GNL_SRCS)

OBJS		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)



# ==================  LIBS  ================== #

# Minilibx
DIR_MLX		:= lib/minilibx-linux
MLX			:= $(DIR_MLX)/libmlx_Linux.a
FLAGS_MLX	:= -L./$(DIR_MLX)
ADD_LIB		:= -lmlx -lm -lX11 -lXext

# Libft
DIR_LIB		:= lib/libft
LIBFT		:= $(DIR_LIB)/libft.a



# ================= COMMANDS ================= #

all: $(NAME)
	@clear
	@echo $(GREEN)"💫 All compiled 💫\n"$(NC)

$(MLX):
	@$(MAKE) -C $(DIR_MLX) -s

$(LIBFT):
	@$(MAKE) -C $(DIR_LIB) -s

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(FLAGS_MLX) $(ADD_LIB) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"\n✨ cub3d build created. ✨\n"$(NC)

# Compilation .c -> .o
$(BUILD_DIR)/%.o: %.c
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
