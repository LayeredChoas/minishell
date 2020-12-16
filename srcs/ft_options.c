/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:38:03 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/15 20:09:19 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_fix_com(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

void	ft_options_run(char **com)
{
	if (!ft_strcmp(com[0], "echo"))
		ft_echo(&com[1]);
	else if (!ft_strcmp(com[0], "exit"))
		ft_exit(&com[1]);
	else if (!ft_strcmp(com[0], "env") && com[1] == NULL)
		ft_env();
	else if (!ft_strcmp(com[0], "cd"))
		ft_cd(&com[1]);
	else if (!ft_strcmp(com[0], "export"))
		ft_export(&com[1]);
	else if (!ft_strcmp(com[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(com[0], "unset"))
		ft_unset(&com[1]);
	else
		ft_execve_run(com);
}

void	ft_options(char *str)
{
	char	**com;
	char	**re_com;

	re_com = NULL;
	com = NULL;
	if (!(re_com = ft_adv_split(str, ' ')) || re_com[0] == NULL)
		return ;
	com = ft_rewrite_com(re_com);
	ft_fix_com(com[0]);
	ft_options_run(com);
	ft_free_double(com);
	ft_free_double(re_com);
	if (g_red.in != g_in)
		g_red.in = g_in;
	if (g_red.out != g_out)
		g_red.out = g_out;
	if (g_pp == 1)
		exit(0);
}
