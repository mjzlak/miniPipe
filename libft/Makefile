# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 14:45:26 by mjzlak            #+#    #+#              #
#    Updated: 2024/11/24 20:00:05 by mloeffer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -include libft.h

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_atoi.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_split.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS_SRC = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

NAME = libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c Makefile libft.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: bonus
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: clean 
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: fclean
re: fclean all
