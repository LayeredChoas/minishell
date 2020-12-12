/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:46 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/11 20:32:08 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_init_2(void)
{
	g_syntax_semi = ft_strdup("syntax error near unexpected token `;\'\n");
	g_syntax_pipe = ft_strdup("syntax error near unexpected token `|\'\n");
	g_syntax_red = ft_strdup("syntax error near unexpected token\
	(unvalid multiple > or <)\n");
	g_id_mini = 0;
}

void	ft_env_init(void)
{
	extern char **environ;
	int			i;
	char		*s1;
	char		*s2;

	g_env_tab = ft_add_to_tab(g_env_tab, "TERM", "xterm");
	if (environ == NULL || !environ[0])
		return ;
	i = 0;
	while (environ[i] != NULL)
	{
		s1 = ft_cpy_stop(environ[i], '=');
		s2 = ft_cpy_after(environ[i], '=');
		g_env_tab = ft_add_to_tab(g_env_tab, s1, s2);
		free(s1);
		free(s2);
		i++;
	}
	ft_init_paths();
	return ;
}

int		init(void)
{
	g_env_str = NULL;
	g_parse_line = NULL;
	g_in = dup(0);
	g_out = dup(1);
	g_fail = 0;
	g_exit = 0;
	g_pp = 1;
	g_red.arg = ft_strdup("");
	g_red.out = g_out;
	g_red.in = g_in;
	g_fork_id = 0;
	g_red.cmd = NULL;
	ft_init_2();
	g_env_back = ft_char_add(NULL, ".");
	ft_env_init();
	ft_init_pwd();
	return (1);
}
