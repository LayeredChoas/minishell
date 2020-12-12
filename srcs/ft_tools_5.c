/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:46:30 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/09 20:00:30 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_test_semi(char **cmd)
{
	int i;
	int j;
	int ex;

	j = 0;
	i = 0;
	ex = 0;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] == '\t' || cmd[i][j] == ' ' || cmd[i][j] == '\n'
		|| cmd[i][j] == '\v' || cmd[i][j] == '\f' || cmd[i][j] == '\r')
			j++;
		if (j == (int)ft_strlen(cmd[i]))
		{
			ex = 1;
			break ;
		}
		i++;
	}
	(ex == 1) ? ft_free_double(cmd) : 1;
	(ex == 1) ? ft_error_print(g_syntax_semi, 2) : 1;
	return (ex);
}

void	ft_free_env(t_env *str)
{
	int i;

	i = 0;
	while (str[i].end)
	{
		ft_free(str[i].key);
		ft_free(str[i].value);
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_fix_paths(char **path)
{
	int i;

	i = 0;
	if (path == NULL)
		return ;
	while (path[i] != NULL)
	{
		if (path[i][ft_strlen(path[i]) - 1] == '/')
			path[i][ft_strlen(path[i]) - 1] = '\0';
		i++;
	}
}

int		ft_get_path(char *str)
{
	char	*tmp;
	int		i;
	DIR		*path;
	int		ex;

	ex = 0;
	i = 0;
	tmp = NULL;
	tmp = ft_strjoin(str, "/");
	path = opendir(tmp);
	if (path == NULL)
	{
		free(tmp);
		return (-1);
	}
	closedir(path);
	free(tmp);
	return (1);
}

int		ft_path_coms(char **com)
{
	int x;

	x = 0;
	execve(com[0], com, g_env_str);
	x = ft_get_path(com[0]);
	if (x == -1)
	{
		ft_putstr_fd(com[0], 2);
		ft_error_print(": No such file or directory\n", 127);
		return (0);
	}
	ft_putstr_fd(com[0], 2);
	ft_error_print(": Is a directory\n", 126);
	exit(126);
	return (1);
}
