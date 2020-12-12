/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:33:31 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/07 20:45:03 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-128);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

char	**ft_rewrite_com(char **re_com)
{
	char	**s1;
	int		i;

	i = 0;
	if (re_com[i] == NULL)
		return (NULL);
	s1 = NULL;
	s1 = (char**)malloc(sizeof(char*) * (ft_str2dlen(re_com) + 1));
	while (re_com[i] != NULL)
	{
		s1[i] = ft_rewrite(re_com[i]);
		i++;
	}
	s1[i] = NULL;
	return (s1);
}

int		ft_putstr(char *str)
{
	if (str == NULL)
		return (0);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

t_env	*ft_remove_key(t_env *tab, int x)
{
	t_env	*new;
	int		j;
	int		i;

	j = 0;
	new = malloc(sizeof(t_env) * (ft_tab_len(tab)));
	i = 0;
	while (tab[i].end == 1)
	{
		if (i == x)
		{
			free(tab[x].key);
			free(tab[x].value);
			i++;
		}
		new[j] = tab[i];
		i++;
		j++;
	}
	new[j].end = 0;
	free(tab);
	return (new);
}

t_env	*ft_remove_tab(t_env *tab, char *key)
{
	t_env	*new;
	int		i;

	i = 0;
	if (tab == NULL || tab[0].end == 0)
		return (tab);
	while (tab[i].end == 1)
	{
		if (ft_strncmp(tab[i].key, key, ft_strlen(key)) == 0)
		{
			new = ft_remove_key(tab, i);
			return (new);
		}
		i++;
	}
	return (tab);
}
