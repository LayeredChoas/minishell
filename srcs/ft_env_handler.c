/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:04:07 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/06 19:54:34 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

size_t	ft_count_av(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '=')
		i++;
	return (i);
}

char	*ft_cpy_stop(char *s1, char c)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	str = NULL;
	str = malloc(sizeof(char) * (ft_count_av(s1) + 1));
	while (s1[i] && s1[i] != c)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_cpy_after(char *s1, char c)
{
	int		i;
	int		len;
	char	*str;

	i = (int)c;
	len = 0;
	i = len;
	str = NULL;
	len = ft_strlen(s1) - ft_count_av(s1);
	str = malloc(sizeof(char) * (len + 1));
	i = ft_count_av(s1) + 1;
	len = ft_count_av(s1) + 1;
	while (s1[i] != '\0')
	{
		str[i - len] = s1[i];
		i++;
	}
	str[i - len] = '\0';
	return (str);
}

t_env	*ft_add_new_tab(t_env *tab, char *key, char *value)
{
	t_env	*new;

	(void)tab;
	new = malloc(sizeof(t_env) * 2);
	new[1].end = 0;
	new[0].key = ft_strdup(key);
	new[0].value = ft_strdup(value);
	new[0].end = 1;
	return (new);
}

t_env	*ft_add_to_tab(t_env *tab, char *key, char *value)
{
	t_env	*new;
	int		i;
	char	*temp;

	i = 0;
	if (tab == NULL)
		return (ft_add_new_tab(tab, key, value));
	while (tab[i].end == 1)
	{
		if (ft_strcmp(tab[i].key, key) == 0)
		{
			temp = tab[i].value;
			tab[i].value = ft_strdup(value);
			free(temp);
			return (tab);
		}
		i++;
	}
	new = ft_copy_tab(tab);
	new[ft_tab_len(tab)].key = ft_strdup(key);
	new[ft_tab_len(tab)].value = ft_strdup(value);
	new[ft_tab_len(tab)].end = 1;
	new[ft_tab_len(tab) + 1].end = 0;
	free(tab);
	return (new);
}
