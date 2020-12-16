/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exceve_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:56:01 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/16 17:20:12 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_exec_path(char **com)
{
	char *tmp;
	char *path;
	char *dir;

	tmp = NULL;
	path = NULL;
	dir = NULL;
	if (com[0][1] != '.')
		tmp = ft_strjoin(g_paths.pwd, &com[0][1]);
	else if (com[0][1] == '.')
	{
		chdir("..");
		dir = getcwd(path, 1024);
		chdir(g_paths.pwd);
		tmp = ft_strjoin(dir, &com[0][2]);
	}
	execve(tmp, com, g_env_str);
	free(tmp);
	free(dir);
	ft_putstr_fd(com[0], 2);
	ft_error_print(": No such file or directory\n", 127);
}

int		ft_added_exec(char **com)
{
	if (com[0][0] == '.')
		ft_exec_path(com);
	else
		ft_path_coms(com);
	exit(127);
}
