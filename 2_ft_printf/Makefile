# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwang <sehwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/14 00:17:39 by sehwang           #+#    #+#              #
#    Updated: 2021/03/19 02:45:26 by sehwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

SRCS = ft_printf.c ft_parse_flags.c ft_treat_types.c ft_convert.c

SRCS_B =

OBJS = $(SRCS:.c=.o)

OBJS_B =

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
		make -C ./libft
		cp ./libft/libft.a ./$(NAME)
		$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_B)
		$(AR) $(NAME) $(OBJS_B)

all: $(NAME)

clean:
		rm -f $(OBJS)
		make clean -C ./libft

fclean: clean
		rm -f $(NAME)
		make fclean -C ./libft

re: clean all

.PHONY: all clean fclean re
