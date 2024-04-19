/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signals_execute(void)
{
	struct termios	termios;

	if (tcgetattr(STDIN_FILENO, &termios) == -1)
		return ;
	termios.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termios) == -1)
		return ;
	signal(SIGINT, &ft_cc_execute);
	signal (SIGQUIT, &ft_cr_execute);
}

static void	ft_start(t_master *master, int argc, char **argv, char **envp)
{
	char	*aux;

	ft_signals();
	ft_create_envp(master, envp);
	ft_unset(master, master->envp, "OLDPWD");
	master->pwdflag = 0;
	if (ft_is_in_envp(master->envp, "HOME"))
	{
		aux = ft_get_value_envp(master, "HOME");
		master->home = ft_strdup(aux);
	}
	else if (ft_is_in_envp(master->envp, "USER"))
	{
		aux = ft_get_value_envp(master, "USER");
		master->home = ft_strjoin("/Users/", aux);
		free(aux);
	}
	else
		master->home = NULL;
	master->test_mode = TRUE;
	if (master->test_mode == TRUE)
		ft_test_mode(master, argc, argv);
	master->list = NULL;
	master->str = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_master	master;
	char		*str;

	ft_start(&master, argc, argv, envp);
	while (argc && argv && envp)
	{
		str = readline(ANSI_COLOR_SHELL"🤖 Minishell ➤ "ANSI_COLOR_RESET);
		ft_signals_execute();
		if (!str)
			exit (g_returnvalue);
		else
		{
			add_history(str);
			ft_parse_exec(&master, str);
			ft_signals();
			ft_clean_master_middle(&master);
		}
	}
	return (0);
}
