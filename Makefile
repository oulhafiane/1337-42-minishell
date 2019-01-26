# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 23:47:07 by zoulhafi          #+#    #+#              #
#    Updated: 2019/01/18 01:54:55 by zoulhafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
PATH_INCLUDES = includes/
LIBFT_INCLUDES = libft/includes/
DEPS = includes/minishell.h libft/includes/libft.h
FLAGS = -Wall -Wextra -Werror
PATH_SRC = srcs/
SRCS = minishell.c builtin.c errors.c ft_echo.c ft_cd.c ft_env.c ft_pwd.c env.c free.c args.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): make_libft $(DEPS) $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -L libft -lft

make_libft:
	make -C libft re

%.o: $(PATH_SRC)%.c
	gcc $(FLAGS) -c $< -I $(PATH_INCLUDES) -I $(LIBFT_INCLUDES)

clean:
	make -C libft clean
	rm -Rf $(OBJS)

fclean: clean
	make -C libft fclean
	rm -Rf $(NAME)

re: fclean all
