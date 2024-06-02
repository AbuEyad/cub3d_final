# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 15:19:58 by habu-zua          #+#    #+#              #
#    Updated: 2024/06/02 17:56:36 by habu-zua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	src/ft_cub3d.c \
		src/ft_read_map.c \
		src/ft_parse_info.c \
		src/ft_parse_info_2.c \
		src/ft_parse_map.c \
		src/ft_get_info.c \
		src/ft_error.c \
		src/ft_init.c \
		src/ft_utils.c \
		src/ft_utils2.c \
		src/ft_split.c \
		src/ft_strdup_map.c \
		src/ft_utils3.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/ft_fill_map.c \
		src/ft_keyboard_action.c \
		src/ft_movement_player.c \
		src/ft_mini_map.c \
		src/ft_exit_prog.c \
		src/ft_raycaster.c \
		src/ft_texture.c \
		src/ft_putstr.c\
		src/ft_memcpy.c \
		src/ft_draw_wall_color.c \
		src/ft_draw_wall_texture.c \
		src/ft_init_storage.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS =  -Wall -Werror -Wextra #-fsanitize=address -g3

RM = /bin/rm

MLX = libs/mlx-mac

LINKS = -lm -L $(MLX) 

LINKS += -lmlx -framework OpenGL -framework AppKit

INCLUDE = ./include

HEADER	= -Iinclude -I/usr/include -I$(MLX)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} $(HEADER)

all : $(NAME)

$(NAME): $(OBJS) $(include)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re