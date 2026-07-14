# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/07/14 17:28:07 by nbaudoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ================= VARIABLES ================= #

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
MAKEFLAGS	+= --no-print-directory
BUILD_DIR	:= .cub3d

NAME		:= cub3d

# Includes
INCLUDES	:=								\
				-Iincludes					\
				-Ilib/minilibx-linux/		\
				-Ilib/libft/				\
				-Ilib/get_next_line/

# Colors
GREEN		:='\033[0;32m'
NC			:='\033[0m'

# Sources

INIT_DIR	= srcs/init
INIT_SRCS	= ${INIT_DIR}/init_data.c	\
			${INIT_DIR}/get_direction.c

EVENT_UI_DIR= srcs/events/ui
EVENT_UI_SRCS= ${EVENT_UI_DIR}/close.c

ERROR_DIR	= srcs/error
ERROR_SRCS	= $(ERROR_DIR)/error.c		\
			$(ERROR_DIR)/debug.c

EVENT_DIR	= srcs/events
EVENT_SRCS	= ${EVENT_DIR}/hook_manager.c ${EVENT_UI_SRCS}



PARSER_DIR	= srcs/parser
PARSER_SRCS	= $(PARSER_DIR)/args.c					\
			$(PARSER_DIR)/map/get_lines.c			\
			$(PARSER_DIR)/map/init_full_file.c		\
			$(PARSER_DIR)/map/check_walls.c			\
			$(PARSER_DIR)/map/init_maze.c			\
			$(PARSER_DIR)/map/is_invalid_line.c		\
			$(PARSER_DIR)/map/init_maze_content.c

ERROR_DIR	= srcs/error
ERROR_SRCS	= $(ERROR_DIR)/error.c		\
			$(ERROR_DIR)/debug.c

FREE_DIR	= srcs/free
FREE_SRCS	= ${FREE_DIR}/free.c

UTILS_DIR	= srcs/utils
UTILS_SRCS	= $(UTILS_DIR)/fill_null.c			\
			$(UTILS_DIR)/image.c ${UTILS_DIR}/split.c	\
			$(UTILS_DIR)/open_fd.c ${UTILS_DIR}/rgb_checks.c

SRCS		:= srcs/main.c $(PARSER_SRCS) $(ERROR_SRCS) ${FREE_SRCS} \
				${INIT_SRCS} $(UTILS_SRCS) ${EVENT_SRCS}

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
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
