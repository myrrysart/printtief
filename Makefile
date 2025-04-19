# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:29:30 by jyniemit          #+#    #+#              #
#    Updated: 2025/04/19 15:50:48 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Isrc -Iinclude
DEBUGFLAG = -g
SRCPATH = ./src
SRCS = ft_printf.c \
		handle_hex_low.c \
		handle_hex_up.c \
		handle_u.c \
		handle_d.c \
		handle_p.c \
		handle_s.c \
		handle_c.c \

OBJPATH = ./obj
OBJS = $(addprefix $(OBJPATH)/, $(SRCS:.c=.o))

all:$(NAME)

$(NAME):$(OBJPATH) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	@echo "removing object files."
	rm -rf $(OBJPATH)

fclean:clean
	@echo "removing $(NAME)"
	rm -f $(NAME)

re:fclean all

debug: CFLAGS += $(DEBUGFLAG)
debug: re
	@echo "Building a debug version of the executable by adding -g to flags"
.PHONY:re fclean clean all debug
