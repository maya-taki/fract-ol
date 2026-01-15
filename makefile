# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 19:04:21 by mtakiyos          #+#    #+#              #
#    Updated: 2026/01/14 21:39:40 by mtakiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol

CC			:= cc
RM			:= rm -rf
RMDIR		:= rm - rf
INCLUDE		:= include/
FLAGS		:= -I$(INCLUDE) -Wall -Werror -Wextra

MLX_DIR		:= minilibx
MLX			:= $(MLX_DIR)/libmlx.a

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	:= -L$(LIBFT_DIR) -lft

INCLUDE_DIR	:= inc $(LIBFT_DIR)
INCLUDES	:= $(foreach dir, (INCLUDE_DIR), -I$(dir))
SRC_DIR		:= src
OBJ_DIR		:= build

YELLOW		:= \033[33m
RED			:= \033[31m
GREEN		:= \033[32m
BLUE		:= \033[34m
END			:= \033[0m

#TODO srcs

SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS_MANDATORY_NAMES))
OBJS		:= $(addprefix $(OBJ_DIR)/,$(SRCS_MANDATORY_NAMES:.c=.o))


# SRCS		:= $(shell find $(SRC_DIRS) -name "*.c")
# OBJS		:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	FLAGS += -g2 - O0
endif

all: $(NAME)

${NAME}: $(OBJS) $(LIBFT) $(MLX)
	@echo "$(YELLOW)🔧 Linking objects...$(RESET)"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) built successfully!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW) Building libft...$(RESET)"
	@$(MAKE) -C ./libft --silent
	@echo "$(GREEN) Libft succesfully created!$(RESET)"

clean:
	@$(RMDIR) $(OBJ_DIR)
	@$(MAKE) clean -C ./libft --silent
	@echo "$(RED) Object files deleted.$(RESET)"
	
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) Deleted everything!$(RESET)"

re: fclean all

norminette:
	@echo "$(YELLOW) Running norminette...$(RESET)"
	@norminette $(SRC) -R CheckForbiddenSourceHeader || true

.PHONY: all clean fclean re run norminette