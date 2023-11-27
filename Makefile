# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:58:16 by dajimene          #+#    #+#              #
#    Updated: 2023/11/27 10:48:20 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -I
RM			:= rm -f
RF			:= rm -rf


INCLUDE		:= include/push_swap.h
LIBFT		:= Libft/libft.a
LIBFT_DIR	:= Libft/
OBJ_DIR		:= obj/
SRC_DIR		:= src/

SRC_FILES	:= main swap tiny_sort utils split_and_process rotate push\
				reverse_rotate push_swap parse_and_init_stack init_nodes\
				free_and_exit check_params
SRC		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) include/push_swap.h
		@echo "\033[33m --Compiling libft--"
		@make -C $(LIBFT_DIR)
		@echo "\033[33m --Compiling push_swap--"
		@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJS) -o $(NAME)
		@echo "\033[0;92m --libft compiled--"
		@echo "\033[0;92m --push_swap compiled--"
		@echo "\033[0;92mUsage: ./push_swap 43 6 35 2 0"

$(OBJ_DIR)%.o: $(SRC_DIR)%.C
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(INCLUDE) -I $(LIBFT_DIR) -c $< -o $@

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) $(OBJS)

fclean: clean
			@make fclean -C $(LIBFT_DIR)
			@$(RF) $(OBJ_DIR)
			@$(RM) $(NAME)
			@echo "033[0;91m--ALL CLEANED!--"

re:			fclean all

.PHONY:		all clean fclean re