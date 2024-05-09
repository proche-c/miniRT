SRCS = ${CHECKERS} ${EXECUTE} ${PARSE} ${UTILS} ${CLEAN} ${MAIN}

CHECKERS = ./src/checkers/check.c \

EXECUTE = ./src/execute/execute.c \

PARSE = ./src/parse/parse.c \
	./src/parse/camera.c \
	./src/parse/ambient.c \
	./src/parse/light.c \
	./src/parse/planes.c \
	./src/parse/spheres.c \
	./src/parse/cylinders.c \

UTILS =	./src/utils/utils_parse.c \

# LISTS = ./src/lists/parse.c \
# 	./src/lists/envp.c \
# 	./src/lists/redir.c \
# 	./src/lists/files.c \
# 	./src/lists/args.c \

CLEAN = ./src/clean/clean.c \
	./src/clean/clean_elements.c \

MAIN = ./src/minirt.c \

OBJS = $(SRCS:.c=.o)

NAME = minirt

HEADER = ./include/minirt.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g $(INC)


INCS        = -I ./include/

RM = rm -f

all: $(NAME) library

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
	@echo "files .o generated"

$(NAME): $(OBJS) $(HEADER) library
	$(CC) $(CFLAGS) $(OBJS)  -L./libft -lft -o $(NAME)
	@echo "file .out generated"

library:
	@$(MAKE) -s -C libft
	@cp libft/libft.a .

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C libft clean
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
	@leaks  -atExit -- ./minirt scene.rt
