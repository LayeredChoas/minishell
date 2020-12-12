/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:07:09 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/11 20:55:37 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_str2dlen(char **str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

int		ft_no_cmd(char **com)
{
	execve(com[0], com, g_env_str);
	ft_putstr_fd(com[0], 2);
	ft_error_print(": command not found\n", 127);
	exit(127);
}

int		ft_execve_fun(char **com)
{
	char	**path;
	char	*tmp;
	char	*tmp1;
	int		i;

	i = 0;
	ft_env_str();
	if (com[0][0] == '/')
	{
		ft_path_coms(com);
		exit(127);
	}
	path = ft_find_path();
	while (path != NULL && path[i] != NULL)
	{
		tmp1 = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp1, com[0]);
		ft_free(tmp1);
		execve(tmp, com, g_env_str);
		ft_free(tmp);
		i++;
	}
	(i == ft_str2dlen(path)) ? ft_no_cmd(com) : 1;
	return (0);
}

int		ft_status_num(int num)
{
	if (num && (g_fail == 131 || g_fail == 130))
		return (g_fail);
	return (WEXITSTATUS(num));
}

void	ft_execve_run(char **str)
{
	int		status;
	char	*tmp;

	g_fail = 0;
	g_id_mini = 0;
	status = 0;
	if (str[0] != NULL)
	{
		tmp = g_last_cmd;
		g_last_cmd = ft_strdup(str[0]);
		ft_free(tmp);
	}
	if (g_pp == 0)
	{
		g_id_mini = fork();
		if (g_id_mini != 0)
			wait(&status);
		else
			ft_execve_fun(str);
		g_fail = ft_status_num(status);
	}
	else
		ft_execve_fun(str);
	g_id_mini = 0;
}
