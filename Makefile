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

CFLAGS = -Wall -Wextra -Werror -I./include #-fsanitize=leak

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
	@leaks -atExit -- ./minirt scenes/camx.rt
