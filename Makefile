# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/07/11 11:40:34 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ================= VARIABLES ================= #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
MAKEFLAGS	+= --no-print-directory
BUILD_DIR	:= .cub3d

NAME		:= cub3d

# Includes
INCLUDES	:=							\
				-Iincludes				\
				-Ilib/minilibx-linux/	\
				-Ilib/libft/			\
				-Ilib/get_next_line/

# Colors
GREEN		:='\033[0;32m'
NC			:='\033[0m'

# Sources

ERROR_DIR	= srcs/error
ERROR_SRCS	= $(ERROR_DIR)/error.c

FREE_DIR	= srcs/free
FREE_SRCS	= ${FREE_DIR}/free.c

PARSER_DIR	= srcs/parser
PARSER_SRCS	= $(PARSER_DIR)/args.c $(PARSER_DIR)/map.c	\
				$(PARSER_DIR)/map/get_lines.c	\
				$(PARSER_DIR)/map/init_map.c	\
				$(PARSER_DIR)/map/map.c			\

SRCS		:= srcs/main.c $(PARSER_SRCS) $(ERROR_SRCS) ${FREE_SRCS}

OBJS		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)



# ==================  LIBS  ================== #

# Minilibx (submodule git)
DIR_MLX		:= lib/minilibx-linux
MLX			:= $(DIR_MLX)/libmlx_Linux.a
FLAGS_MLX	:= -L./$(DIR_MLX)
ADD_LIB		:= -lmlx -lm -lX11 -lXext

# GNL
DIR_GNL		:= lib/get_next_line
GNL			:= $(DIR_GNL)/get_next_line.a

# Libft
DIR_LIB		:= lib/libft
LIBFT		:= $(DIR_LIB)/libft.a



# ================= COMMANDS ================= #

all: $(NAME)
	@echo $(GREEN)"💫 All compiled 💫\n"$(NC)

$(MLX):
	@if [ ! -f "$(DIR_MLX)/Makefile" ]; then \
		git submodule update --init $(DIR_MLX); \
	fi
	@$(MAKE) -C $(DIR_MLX) -s

$(LIBFT):
	@$(MAKE) -C $(DIR_LIB) -s

$(GNL):
	@$(MAKE) -C $(DIR_GNL) -s

$(NAME): $(OBJS) $(MLX) $(LIBFT) $(GNL)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIBFT) $(FLAGS_MLX) $(ADD_LIB) -o $(NAME)
	@echo $(GREEN)"\n✨ cub3d build created. ✨\n"$(NC)

# Compilation .c -> .o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@if [ -f "$(DIR_MLX)/Makefile" ]; then $(MAKE) -C $(DIR_MLX) clean -s; fi
	@$(MAKE) -C $(DIR_LIB) clean -s
	@$(MAKE) -C $(DIR_GNL) clean -s
	@rm -rf $(BUILD_DIR)
	@echo $(GREEN)"cub3d build is clean. 🧹"$(NC)

fclean: clean
	@$(MAKE) -C $(DIR_LIB) fclean -s
	@$(MAKE) -C $(DIR_GNL) fclean -s
	@rm -f $(NAME)
	@echo $(GREEN)"cub3d library is clean. 🧹"$(NC)

re: fclean
	$(MAKE) all

.SILENT:
.PHONY: all clean fclean re
