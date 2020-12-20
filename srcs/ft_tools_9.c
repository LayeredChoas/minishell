/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:26:21 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/20 11:56:20 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

char	*ft_strcut(char *str, int start, int len)
{
	char	*s;
	int		num;
	int		i;

	i = 0;
	num = 0;
	s = NULL;
	if (len == 0 || start >= (int)ft_strlen(str))
		return (ft_strdup(""));
	if (len < 0)
		len = ft_strlen(str) - start;
	s = (char*)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		s[i] = str[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

int		ft_skip_q(char *str, char type)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != type)
		i++;
	return (i + 1);
}

char	*ft_paths_ret(char *str)
{
	if (ft_strcmp(str, "PWD") == 0 && g_paths.pwd)
		return (ft_strdup(g_paths.pwd));
	if (ft_strcmp(str, "OLDPWD") == 0 && g_paths.oldpwd)
		return (ft_strdup(g_paths.oldpwd));
	return (ft_strdup(""));
}

int		ft_home_check(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (g_env_tab[i].end)
	{
		if (ft_strcmp(str, g_env_tab[i].key) == 0)
		{
			tmp = g_paths.oldpwd;
			g_paths.oldpwd = ft_strdup(g_env_tab[i].value);
			(tmp) ? free(tmp) : 1;
			return (1);
		}
		i++;
	}
	free(g_paths.oldpwd);
	g_paths.oldpwd = NULL;
	return (0);
}

char	*ft_home(void)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (g_env_tab[i].end)
	{
		if (ft_strcmp("HOME", g_env_tab[i].key) == 0)
			return (g_env_tab[i].value);
		i++;
	}
	return (NULL);
}
