/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:32:32 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/10 17:40:49 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_find_key(char *str)
{
	int i;

	i = 0;
	if (str != NULL && str[0] == '?' && str[1] == '\0')
		return (ft_itoa(g_fail));
	while (g_env_tab[i].end)
	{
		if (ft_strcmp(g_env_tab[i].key, str) == 0)
			return (ft_strdup(g_env_tab[i].value));
		i++;
	}
	return (ft_paths_ret(str));
}

t_env	*ft_copy_tab(t_env *tab)
{
	t_env	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_env) * (ft_tab_len(tab) + 2));
	while (tab[i].end == 1)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}

int		ft_check_key_error(char *key)
{
	int i;

	i = 0;
	if (!ft_isalpha(key[0]))
		return (1);
	while (key[i] != '\0')
	{
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_slash(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && str[i - 1] && str[i - 1] != '\\')
		{
			j = i;
			while (str[j] != '\0')
			{
				str[j] = str[j + 1];
				j++;
			}
			break ;
		}
		i++;
	}
}
