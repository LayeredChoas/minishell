/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:36:20 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/08 20:05:23 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_in_sq(char *str, char change, char to)
{
	g_i++;
	while (str[g_i] != '\'' && str[g_i] != '\0')
	{
		if (str[g_i] == change)
			str[g_i] = to;
		g_i++;
	}
}

void	ft_in_dq(char *str, char change, char to)
{
	g_i++;
	while ((str[g_i] != '"' && str[g_i] != '\0') ||
	(str[g_i - 1] != '\0' && str[g_i - 1] == '\\' && str[g_i] == '"'))
	{
		if (str[g_i] == change)
			str[g_i] = to;
		g_i++;
	}
}

int		ft_change_char(char *str, char change, char to)
{
	int j;

	j = 0;
	g_i = 0;
	while (str[g_i] != '\0')
	{
		if (str[g_i] == '\'')
			ft_in_sq(str, change, to);
		else if (str[g_i] == '"' && str[g_i] != '\0' && str[g_i - 1] != '\\')
			ft_in_dq(str, change, to);
		g_i++;
	}
	g_i = 0;
	return (0);
}

int		ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_white_space_fix(char *s)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (s[i] != '\0')
	{
		if (s[i] == '"' && s[i - 1] != '\\')
		{
			i++;
			while (s[i] != '\0' && (s[i] != '"' ||
			(s[i] == '"' && s[i - 1] != '"')))
				i++;
		}
		else if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
		}
		else if (ft_is_whitespace(s[i]) == 1)
			s[i] = c;
		i++;
	}
	return (0);
}
