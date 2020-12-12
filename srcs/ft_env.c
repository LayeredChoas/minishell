/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:03:18 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/11 20:51:55 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

char	**ft_char_add(char **tab, char *add)
{
	int		i;
	char	**ret;

	i = 0;
	if (ft_check_tab(tab, add) == 1)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (ft_str2dlen(tab) + 2));
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			ret[i] = ft_strdup(tab[i]);
			i++;
		}
	}
	ret[i] = ft_strdup(add);
	ret[i + 1] = NULL;
	return (ret);
}

int		ft_key_exist(char *str)
{
	int i;

	i = 0;
	while (g_env_tab[i].end)
	{
		if (ft_strcmp(g_env_tab[i].key, str) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_export_key_save(char *str)
{
	char **tmp;

	tmp = NULL;
	if (ft_key_exist(str))
		return ;
	tmp = g_env_back;
	g_env_back = ft_char_add(g_env_back, str);
	if (g_env_back == NULL)
		g_env_back = tmp;
	else
		free(tmp);
}

void	ft_env(void)
{
	int i;

	i = 0;
	g_fail = 0;
	ft_env_str();
	while (g_env_str[i] != NULL)
	{
		ft_putstr(g_env_str[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_env_str(void)
{
	int		i;
	int		len;
	char	*temp;

	len = 0;
	i = 0;
	if (g_env_str != NULL)
		ft_free_double(g_env_str);
	while (g_env_tab[len].end)
		len++;
	g_env_str = malloc(sizeof(char*) * (len + 1));
	while (g_env_tab[i].end)
	{
		temp = ft_strjoin(g_env_tab[i].key, "=");
		g_env_str[i] = ft_strjoin(temp, g_env_tab[i].value);
		ft_free(temp);
		i++;
	}
	g_env_str[i] = NULL;
}
