/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adv_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:38:07 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/06 19:31:44 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

static int		c_w(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static int		size_words(char const *s, char c)
{
	int count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static	char	**m_free(char **p, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
			i++;
		}
	}
	free(p);
	return (NULL);
}

void			ft_change_char_tab(char **tab, char c)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_change_char(tab[i], 7, c);
		i++;
	}
}

char			**ft_adv_split(char *s, char c)
{
	char	**tab;
	int		j;
	int		k;

	if (s == NULL || !(tab = (char **)malloc(sizeof(char *) * (c_w(s, c) + 1))))
		return (NULL);
	j = ft_change_char(s, c, 7);
	while (*s)
	{
		while ((*s == c) && *s)
			s++;
		if (*s)
		{
			k = 0;
			if (!(tab[j] = (char *)malloc(sizeof(char) *
							size_words(s, c) + 1)))
				return (m_free(&tab[j], size_words(s, c) + 1));
			while (*s && *s != c)
				tab[j][k++] = *(s++);
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	ft_change_char_tab(tab, c);
	return (tab);
}
