/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:56:01 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/12 11:52:33 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_ctrl_c(int nb)
{
	(void)nb;
	g_fail = 130;
	ft_putstr_fd("\b\b  \b\b", 2);
	if (g_parse_line == NULL)
	{
		write(1, "\n", 1);
		(g_fail != 0) ? ft_putstr("❌") : 1;
		(g_fail == 0) ? ft_putstr("✅") : 1;
		ft_putstr("\033[0;31m");
		ft_putstr(g_paths.pwd);
		ft_putstr(":minishell-> ");
		ft_putstr("\033[0m");
	}
	else
		ft_putstr_fd("\b\b  \b\b", 2);
}

void	ft_ctrl_slash(int nb)
{
	char *num;

	num = NULL;
	num = ft_itoa(nb);
	if (g_parse_line != NULL && ft_strcmp(g_last_cmd, g_exec_name) != 0)
	{
		ft_putstr_fd("\b\b  \b\b", 2);
		ft_putstr("Quit: ");
		ft_putstr(num);
		ft_putstr("\n");
		g_fail = 131;
	}
	else if (ft_strcmp(g_last_cmd, g_exec_name) != 0)
		ft_putstr_fd("\b\b  \b\b", 2);
	free(num);
}

void	ft_catch_signal(void)
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, ft_ctrl_slash);
}
