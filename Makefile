# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:58:16 by dajimene          #+#    #+#              #
#    Updated: 2023/11/28 23:41:43 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
RF			= rm -rf
AR			= ar rcs

INCLUDE		= -I ./include/
LIBFT		= Libft/libft.a
LIBFT_DIR	= Libft/
OBJ_DIR		= obj/
SRC_DIR		= src/

SRC_FILES	= ${shell find src/ -name "*.c"}

SRC		= $(SRC_FILES)
OBJ	= $(subst src/, obj/, $(SRC))
OBJS	= $(OBJ:.c=.o)

.SILENT:

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -I$(LIBFT_DIR) -c $< -o $@
	
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJS)
	@echo "\033[33m --Compiling libft--"
	@make -C $(LIBFT_DIR)
	@echo "\033[0;92m --libft compiled--"
	@echo "\033[33m --Compiling push_swap--"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "\033[0;92m --push_swap compiled--"
	@echo "\033[0;92mUsage: ./push_swap 43 6 35 2 0"

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RF) $(OBJ_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	@echo "\033[0;92m--ALL CLEANED!--"

re:	fclean all

.PHONY:	all clean fclean re