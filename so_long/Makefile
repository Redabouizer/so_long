# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 16:02:52 by rbouizer          #+#    #+#              #
#    Updated: 2024/07/23 18:50:45 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	ft_fd.c\
	ft_check.c\
	main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

NAME = so_long

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c so_long.h  get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all