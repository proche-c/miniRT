SRCS = ${CHECKERS} ${EXECUTE} ${PARSE} ${UTILS} ${CLEAN} ${EVENT} ${MAIN}

CHECKERS = $(wildcard ./src/checkers/*.c)
EXECUTE = $(wildcard ./src/execute/*.c)
PARSE = $(wildcard ./src/parse/*.c)
UTILS =	$(wildcard ./src/utils/*.c)
CLEAN = $(wildcard ./src/clean/*.c)
EVENT = $(wildcard ./src/events/*.c)

# LISTS = ./src/lists/parse.c \
# 	./src/lists/envp.c \
# 	./src/lists/redir.c \
# 	./src/lists/files.c \
# 	./src/lists/args.c \


MAIN = ./src/minirt.c \

OBJS = $(SRCS:.c=.o)

NAME = miniRT

HEADER = ./include/minirt.h

CC = gcc #-fsanitize=address -g

CFLAGS = -Wall -Wextra -Werror -g $(INC)

ifeq ($(shell uname), Linux)
	MDIR   = ./minilibx/linux
	MINC   = ./minilibx/linux
	MFLAGS = -lmlx -lXext -lX11 -lm -lz
else
	MDIR   = ./minilibx/macos
	MINC   = ./minilibx/macos
	MFLAGS = -lmlx -framework openGL -framework AppKit
endif


INCS        = -I ./include/

RM = rm -f

all: $(NAME) library

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(MINC) -c $< -o $@ $(INCS)
	@echo "files .o generated"

$(NAME): $(OBJS) $(HEADER) library
	$(MAKE) -C $(MDIR)
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -L $(MDIR)  -L./libft -lft -o $(NAME)
	@echo "file .out generated"

library:
	@$(MAKE) -s -C libft
	@cp libft/libft.a .

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C libft clean
	$(MAKE) -C $(MDIR) clean
	@echo "files .o removed"

fclean: clean
	@$(RM) $(NAME) libft.a
	@$(MAKE) -s -C libft fclean 
	@echo "Program removed"

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

test: clean re
	@$(RM) $(OBJS)
	@./minirt

leaks: all
	@clear
	@leaks  -atExit -- ./minirt scenes/test.rt
