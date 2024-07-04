SRCS = ${CHECKERS} ${EXECUTE} ${PARSE} ${UTILS} ${CLEAN} ${EVENT} ${MAIN}

CHECKERS = $(wildcard ./src/checkers/*.c)
EXECUTE = $(wildcard ./src/execute/*.c)
PARSE = $(wildcard ./src/parse/*.c)
UTILS = $(wildcard ./src/utils/*.c)
CLEAN = $(wildcard ./src/clean/*.c)
EVENT = $(wildcard ./src/events/*.c)

MAIN = ./src/minirt.c

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

.PHONY: all clean fclean re norme test leaks library

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(MAKE) -C $(MDIR)
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -L$(MDIR) -L./libft -lft -o $(NAME)
	@echo "Executable $(NAME) generated"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(MINC) -c $< -o $@
	@echo "Compiled $< to $@"

libft/libft.a:
	@$(MAKE) -s -C libft
	@cp libft/libft.a .

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C libft clean
	@$(MAKE) -C $(MDIR) clean
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME) libft.a
	@$(MAKE) -s -C libft fclean
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
