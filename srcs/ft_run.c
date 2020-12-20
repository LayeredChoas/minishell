/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:29:36 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/19 12:13:57 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		shell(char **str)
{
	int ret;

	ret = 0;
	(g_fail != 0) ? ft_putstr("❌") : 1;
	(g_fail == 0) ? ft_putstr("✅") : 1;
	ft_putstr("\033[0;31m");
	ft_putstr(g_paths.pwd);
	ft_putstr(":minishell-> ");
	ft_putstr("\033[0m");
	ret = get_next_line(0, str);
	return (ret);
}

int		ft_line_check(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == ' ' ||
		str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	(str[i] == ';') ? ft_error_print(g_syntax_semi, 2) : 1;
	if (str[i] == ';')
		return (1);
	(str[i] == '|') ? ft_error_print(g_syntax_pipe, 2) : 1;
	if (str[i] == '|')
		return (1);
	i = ft_strlen(str) - 1;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == ' ' ||
		str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i--;
	(str[i] == '|') ? ft_error_print(g_syntax_pipe, 2) : 1;
	if (str[i] == '|')
		return (1);
	return (0);
}

void	ft_semi_loop(char **cmds, int test)
{
	int i;

	i = 0;
	while (cmds[i] != NULL && test == 0 && ft_line_check(g_parse_line) == 0)
	{
		if (ft_check_errors_global(cmds[i]) || ft_check_red(cmds[i]))
		{
			ft_error_print("Multiline Error\n", 127);
			break ;
		}
		g_pp = 1;
		ft_white_space_fix(cmds[i]);
		ft_pipe(cmds[i]);
		free(cmds[i]);
		dup2(g_in, 0);
		dup2(g_out, 1);
		if (g_exit != 0)
			break ;
		i++;
	}
}

void	ft_ex_shell(void)
{
	char	**cmds;
	int		test;

	cmds = NULL;
	test = 0;
	cmds = ft_adv_split(g_parse_line, ';');
	test = ft_test_semi(cmds);
	ft_semi_loop(cmds, test);
	(test == 0) ? free(cmds) : 1;
}

void	ft_run_minishell(void)
{
	int		x;
	char	**cmds;

	x = 1;
	g_parse_line = NULL;
	cmds = NULL;
	while (x == 1)
	{
		g_parse_line = NULL;
		g_red.cmd = NULL;
		g_fork_id = 0;
		g_pp = 0;
		if ((x = shell(&g_parse_line)) < 0)
		{
			ft_error_print("Error: Get Next Line Error\n", 127);
			break ;
		}
		if (ft_line_check(g_parse_line) == 0)
			ft_ex_shell();
		free(g_parse_line);
	}
	exit(0);
}
