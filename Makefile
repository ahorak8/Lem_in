# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahorak <ahorak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 07:42:17 by ahorak            #+#    #+#              #
#    Updated: 2018/09/25 10:05:50 by ahorak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

INCLUDES_PATH = ./includes/

SRC_NAME = additions.c farm.c lemming.c links.c main.c notify.c rooms.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC =
