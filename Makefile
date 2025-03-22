# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:03:24 by mel-atti          #+#    #+#              #
#    Updated: 2024/06/11 14:03:30 by mel-atti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PS_DIR = Push_Swap
PS_SRCS = $(wildcard $(PS_DIR)/*.c)
PS_OBJS = $(PS_SRCS:.c=.o)
PS_ARCHIVE = $(PS_DIR)/$(NAME).a

BONUS_NAME = checker
BONUS_DIR = Checker
BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(PS_ARCHIVE): $(PS_OBJS)
	ar -rcs $(PS_ARCHIVE) $(PS_OBJS)

$(NAME): $(PS_ARCHIVE)
	$(CC) $(CFLAGS) $(PS_ARCHIVE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(PS_ARCHIVE) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(PS_ARCHIVE) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	rm -rf $(PS_OBJS) $(BONUS_OBJS) $(PS_ARCHIVE)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
