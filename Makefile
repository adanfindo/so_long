# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afindo <afindo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 17:47:10 by afindo          #+#    #+#              #
#    Updated: 2022/03/02 17:25:51 by afindo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			so_long
NAME_BONUS =	so_long_bonus

MINILIBX_PATH = ./minilibx
MINILIBX =		${MINILIBX_PATH}/libmlx.dylib

CC = 			gcc
CFLAGS = 		-Wall -Werror -Wextra
MLXFLAGS = 		-framework AppKit -framework OpenGL -Lminilibx -lmlx
RM = 			rm -f

SOURCES_FILES = sources/ft_draw.c \
				sources/ft_letsplay.c \
				sources/ft_map_check.c \
				sources/ft_map_read.c \
				sources/ft_player_action.c \
				sources/ft_clear_game.c \
				sources/ft_start_game.c \
				sources/ft_update_map.c \
				sources/so_long.c \
				utils/ft_itoa.c \
				utils/ft_print.c \
				utils/ft_split.c \
				utils/ft_strchr.c \
				utils/get_next_line_utils.c \
				utils/get_next_line.c

SOURCES_BONUS = sources_bonus/ft_clear_game_bonus.c \
				sources_bonus/ft_draw_bonus.c \
				sources_bonus/ft_img_bonus.c \
				sources_bonus/ft_letsplay_bonus.c \
				sources_bonus/ft_map_check_bonus.c \
				sources_bonus/ft_map_read_bonus.c \
				sources_bonus/ft_player_action_bonus.c \
				sources_bonus/ft_start_game_bonus.c \
				sources_bonus/ft_update_map_bonus.c \
				sources_bonus/so_long_bonus.c \
				utils/ft_itoa.c \
				utils/ft_print.c \
				utils/ft_split.c \
				utils/ft_strchr.c \
				utils/get_next_line_utils.c \
				utils/get_next_line.c
				
SOURCES_DIR =	./
BONUS_DIR = 	./

HEADER = 		${SOURCES_DIR}sources/so_long.h
HEADER_BONUS =  ${BONUS_DIR}sources_bonus/so_long_bonus.h

SOURCES = 		$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES	=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS =		${SOURCES:.c=.o} 
OBJECTS_BONUS = $(BONUS_FILES:.c=.o)

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			move_lib $(NAME)

bonus:			move_lib $(NAME_BONUS)

$(NAME):		$(MINILIBX) $(OBJECTS) $(HEADER) 
				$(CC) $(CFLAGS) $(OBJECTS) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):  $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

move_lib:		
				make -C ${MINILIBX_PATH} && cp ${MINILIBX} ${MINILIBX_PATH}/..

clean:
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)
				$(RM) 
				
fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS) ./libmlx.dylib

re:				fclean all

.PHONY: 		all clean fclean re
