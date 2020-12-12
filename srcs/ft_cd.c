/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:09:07 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/11 17:08:56 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_cd_1(char **com)
{
	if (ft_strcmp(com[0], "-") == 0)
	{
		if (ft_home_check("OLDPWD") == 0)
			(!g_paths.oldpwd) ? ft_error_print("cd: OLDPWD not set", 1) : 1;
		else
		{
			ft_putstr(g_paths.oldpwd);
			if (chdir(g_paths.oldpwd) != 0)
			{
				ft_error_print(": No such file or directory", 1);
				g_fail = 1;
			}
			ft_init_pwd();
		}
		ft_putchar('\n');
		return ;
	}
	ft_putstr_fd(com[0], 2);
	ft_error_print(": No such file or directory\n", 1);
}

void	ft_cd(char **com)
{
	int		i;
	int		x;

	i = 0;
	g_fail = 0;
	while (com[i] != NULL)
		i++;
	if (i == 0 || ft_strcmp(com[0], "~") == 0)
	{
		if (!g_paths.home && ft_home_check("HOME") == 0)
			ft_error_print("cd: HOME not set\n", 1);
		else
			chdir(g_paths.home);
		ft_init_pwd();
		return ;
	}
	if (i != 1)
	{
		ft_error_print("cd: too many arguments\n", 1);
		return ;
	}
	x = chdir(com[0]);
	(x < 0) ? ft_cd_1(com) : ft_init_pwd();
	if (x < 0)
		return ;
}
