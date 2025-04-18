# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 14:29:30 by jyniemit          #+#    #+#              #
#    Updated: 2025/04/18 16:06:39 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Isrc -Iinclude
DEBUGFLAG = -g
SRCPATH = ./src
SRCS = printf.c handle_x.c handle_X.c handle_u.c handle_d.c handle_p.c\
       handle_s.c handle_c.c


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
	@rm -rf $(OBJPATH)

fclean:clean
	@rm -f $(NAME)

re:fclean all

debug: CFLAGS += $(DEBUGFLAG)
debug: re
.PHONY:re fclean clean all debug
