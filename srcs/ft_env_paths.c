/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:12:13 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/18 19:23:53 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_error_pwd(void)
{
	ft_putstr_fd("cd: error retrieving current directory: ", 2);
	ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
	ft_putstr_fd("No such file or directory\n", 2);
}

void	ft_init_pwd(int x)
{
	char	*dir;
	char	*buff;
	char	*tmp;

	dir = NULL;
	buff = NULL;
	tmp = NULL;
	dir = getcwd(buff, 10000);
	if (dir == NULL)
	{
		ft_error_pwd();
		return ;
	}
	tmp = g_paths.oldpwd;
	g_paths.oldpwd = g_paths.pwd;
	g_paths.pwd = dir;
	if (x == 1)
	{
		g_env_tab = ft_add_to_tab(g_env_tab, "PWD", g_paths.pwd);
		g_env_tab = ft_add_to_tab(g_env_tab, "OLDPWD", g_paths.oldpwd);
	}
	ft_free(tmp);
}

void	ft_init_paths(void)
{
	int i;

	i = 0;
	while (g_env_tab[i].end)
	{
		if (!ft_strcmp("OLDPWD", g_env_tab[i].key))
			g_paths.oldpwd = ft_strdup(g_env_tab[i].value);
		i++;
	}
}
