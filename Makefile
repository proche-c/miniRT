SRCS = ${BUILTINS} ${DEBUG} ${EXECUTE} ${PARSE} ${UTILS} ${LISTS} ${CLEAN} ${MAIN}

BUILTINS = ./src/builtins/cd_error.c \
	./src/builtins/cd.c \
	./src/builtins/cd_utils.c \
	./src/builtins/echo.c \
	./src/builtins/env_utils.c \
	./src/builtins/env.c \
	./src/builtins/envp_utils.c \
	./src/builtins/envp.c \
	./src/builtins/exit_utils.c \
	./src/builtins/exit.c \
	./src/builtins/export_utils.c \
	./src/builtins/export.c \
	./src/builtins/pwd.c \
	./src/builtins/unset.c \
	./src/builtins/envp_utils_2.c \

EXECUTE = ./src/execute/cmd.c \
	./src/execute/cmd_1.c \
	./src/execute/cmd_2.c \
	./src/execute/cmd_3.c \
	./src/execute/exec_builts.c \
	./src/execute/execute.c \
	./src/execute/execute_cmd_real.c \
	./src/execute/execute_cmd_real_aux.c \
	./src/execute/pipes.c \
	./src/execute/pre_execute.c \
	./src/execute/redirection_input.c \
	./src/execute/redirection_input_utils.c \
	./src/execute/redirections.c \
	./src/execute/utils_execute.c \
	./src/execute/utils_execute2.c \
	./src/execute/utils_execute3.c \

PARSE = ./src/parse/check_str.c \
	./src/parse/utils_quotes.c \
	./src/parse/check_pipes.c \
	./src/parse/check_redir.c \
	./src/parse/check_d_redir.c \
	./src/parse/double_redir.c \
	./src/parse/data.c \
	./src/parse/commands.c \
	./src/parse/entry.c \
	./src/parse/parse.c \
	./src/parse/path.c \
	./src/parse/replace_var.c \
	./src/parse/separate.c \
	./src/parse/separate_cmd.c \
	./src/parse/utils_separate_cmd.c \
	./src/parse/utils_parse.c \
	./src/parse/quotes.c \
	./src/parse/dollar.c \
	./src/parse/utils_dollar.c \
	./src/parse/replace.c \
	./src/parse/replace_tilde.c \
	./src/parse/utils_tilde.c \
	./src/parse/utils_replace.c \

UTILS =	./src/utils/compare_str.c \
	./src/utils/errors.c \
	./src/utils/ft_strjoin_3.c \
	./src/utils/home.c \
	./src/utils/put_str.c \
	./src/utils/returns.c \
	./src/utils/test_mode.c \

LISTS = ./src/lists/parse.c \
	./src/lists/envp.c \
	./src/lists/redir.c \
	./src/lists/files.c \
	./src/lists/args.c \

CLEAN = ./src/clean/clean.c \
	./src/clean/clean_lists.c \
	./src/clean/clean_parse.c \
	./src/clean/clean_env.c \

MAIN = ./src/minishell.c \
	./src/signals.c \

OBJS = $(SRCS:.c=.o)

NAME = minishell

HEADER = ./include/minishell.h

CC = gcc

 CFLAGS		= -Wall -Wextra -Werror -g $(INC) -I ~/.brew/opt/readline/include
#CFLAGS		= -Wall -Wextra -Werror -g $(INC) -I /opt/homebrew/opt/readline/include #M2

INCS        = -I ./include/

RM = rm -f

all: $(NAME) library

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJS) $(HEADER) library
	@$(CC) $(CFLAGS) $(OBJS) -lreadline -L ~/.brew/opt/readline/lib -L./libft -lft -o $(NAME)
#	@$(CC) $(CFLAGS) $(OBJS) -lreadline -L /opt/homebrew/opt/readline/lib -L./libft -lft -o $(NAME) #M2
	
	@echo "\x1b[32mAll compiled\x1b[0m"

library:
	@$(MAKE) -s -C libft
	@cp libft/libft.a .

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C libft clean
	@echo "\x1b[31mObjs removed\x1b[0m"

fclean: clean
	@$(RM) $(NAME) libft.a
	@$(MAKE) -s -C libft fclean 
	@echo "\x1b[31mProgram removed\x1b[0m"

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

test: clean re
	@$(RM) $(OBJS)
	@./minishell

leaks: all
	@clear
	@leaks -atExit -- ./minishell
