# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 16:02:52 by rbouizer          #+#    #+#              #
#    Updated: 2024/07/30 06:31:35 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	utils/ft_split.c\
	utils/ft_strlcpy.c\
	utils/ft_putendl_fd.c\
	utils/ft_putstr_fd.c\
	utils/ft_putchar_fd.c\
	maps/ft_fd.c\
	maps/ft_check.c\
	maps/ft_helps.c\
	maps/ft_find_palyer.c\
	maps/flood_fill.c\
	maps/ft_win.c\
	main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
CC = cc
RM = rm -rf
MLX =  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) 

%.o: %.c so_long.h  get_next_line/get_next_line.h utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all