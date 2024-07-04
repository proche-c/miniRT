/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

SRCS = $(wildcard ./src/checkers/*.c) \
       $(wildcard ./src/execute/*.c) \
       $(wildcard ./src/parse/*.c) \
       $(wildcard ./src/utils/*.c) \
       $(wildcard ./src/clean/*.c) \
       $(wildcard ./src/events/*.c) \
       ./src/minirt.c

OBJS = $(SRCS:.c=.o)

NAME = miniRT

HEADER = ./include/minirt.h ./include/pixel.h

CC = gcc

CFLAGS = -fsanitize=address -Wall -Wextra -Werror -I./include

ifeq ($(shell uname), Linux)
    MDIR = ./minilibx/linux
    MINC = ./minilibx/linux
    MFLAGS = -lmlx -lXext -lX11 -lm -lz
else
    MDIR = ./minilibx/macos
    MINC = ./minilibx/macos
    MFLAGS = -lmlx -framework openGL -framework AppKit
endif

RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re norme test leaks library

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C $(MDIR)
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -L$(MDIR) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "Executable $(NAME) generated"

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(MINC) -c $< -o $@
	@echo "Compiled $< to $@"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	@echo "Library $(LIBFT) built"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MDIR) clean
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME) $(LIBFT)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "Executable and libraries removed"

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

test: clean re
	@$(RM) $(OBJS)
	@./minirt

leaks: all
	@clear
	@leaks -atExit -- ./minirt scenes/test.rt
