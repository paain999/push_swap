# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:58:16 by dajimene          #+#    #+#              #
#    Updated: 2023/11/13 12:39:08 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror
INCLUDE		:= -I include/push_swap.h
LIBFT		:= Libft/libft.a
LIBFT_DIR	:= Libft/

RM			:= rm -f
RF			:= rm -rf

OBJ_DIR		:= obj/
SRC_FILES		:= main

SRC		= $(addsuffix .c, $(SRC_FILES))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

.SILENT:

all: $(NAME)

$()