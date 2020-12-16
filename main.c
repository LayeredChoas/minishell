/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:48:43 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/16 17:48:03 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_minishell.h"

int		main(int ac, char **av)
{
	(void)ac;
	g_exec_name = ft_strdup(av[0]);
	ft_catch_signal();
	init();
	ft_run_minishell();
	ft_free_env(g_env_tab);
	ft_free_double(g_env_str);
	free(g_exec_name);
	free(g_paths.oldpwd);
	free(g_paths.pwd);
	free(g_syntax_pipe);
	free(g_syntax_red);
	free(g_syntax_semi);
	return (0);
}
