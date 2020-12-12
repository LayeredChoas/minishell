/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:18:00 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/10 18:21:06 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_add_key_value(char *key, char *value)
{
	char *tmp;

	tmp = NULL;
	if (ft_strcmp(key, "OLDPWD") == 0)
	{
		tmp = g_paths.oldpwd;
		g_paths.oldpwd = ft_strdup(value);
	}
	if (ft_strcmp(key, "HOME") == 0)
	{
		tmp = g_paths.oldpwd;
		g_paths.oldpwd = ft_strdup(value);
	}
	g_env_tab = ft_add_to_tab(g_env_tab, key, value);
	ft_update_back(key);
	free(tmp);
	ft_free(key);
	ft_free(value);
}

void	ft_export_line(char *s1)
{
	int		i;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	i = 0;
	while (s1 != NULL && s1[i] != '=' && s1[i] != '\0')
		i++;
	if (s1[i] == '=')
	{
		key = ft_strcut(s1, 0, i);
		value = ft_strcut(s1, i + 1, -1);
		if (ft_check_key_error(key))
		{
			ft_export_error(s1);
			free(key);
			free(value);
			return ;
		}
		ft_add_key_value(key, value);
		return ;
	}
	(ft_check_key_error(s1) == 1) ? (void)ft_export_error(s1) : 1;
	(ft_check_key_error(s1) == 0) ? ft_export_key_save(s1) : 1;
}

void	ft_print_unsed(void)
{
	int i;

	i = 0;
	while (g_env_back[i] != NULL)
	{
		if (g_env_back[i][0] != '.' && g_env_back[i][0] != '\0')
		{
			ft_putstr("declare -x ");
			ft_putstr(g_env_back[i]);
			ft_putstr("\n");
		}
		i++;
	}
}

void	ft_simple_export(void)
{
	int i;
	int j;

	j = 0;
	i = 0;
	ft_env_str();
	while (g_env_str[i] != NULL)
	{
		j = 0;
		ft_putstr("declare -x ");
		while (g_env_str[i][j - 1] != '=')
			(ft_putchar(g_env_str[i][j]) == 1) ? j++ : 0;
		ft_putchar('"');
		ft_putstr(&g_env_str[i][j]);
		ft_putstr("\"\n");
		i++;
	}
	ft_print_unsed();
}

void	ft_export(char **com)
{
	int i;

	i = 0;
	g_fail = 0;
	if (!com[0])
		ft_simple_export();
	while (com[i] != NULL)
	{
		ft_export_line(com[i]);
		i++;
	}
	return ;
}
