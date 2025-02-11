# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 08:27:01 by mjzlak            #+#    #+#              #
#    Updated: 2025/01/24 10:24:09 by mloeffer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   error_handling.c \
	   error_handling_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY : all
all: $(LIBFT) $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

.PHONY : clean
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

.PHONY : fclean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

.PHONY : re
re: fclean all
