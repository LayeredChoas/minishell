/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:29:29 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/19 12:11:41 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_fix_mid(char *str)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && str[i + 1] == '\"')
		{
			j = i;
			count++;
			while (str[i + 1] != '\0')
			{
				str[i] = str[i + 1];
				i++;
			}
			i = j;
		}
		i++;
	}
	str[i - count] = '\0';
}

char	*ft_addr(char *str, int start, int *num)
{
	int		i;
	int		count;
	char	*names[3];
	char	*ret;
	char	*value;

	count = 0;
	i = start + 1;
	while (str[i] && ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 &&
	str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) ||
	str[i] == '_' || str[i] == '?'))
	{
		count++;
		i++;
	}
	names[0] = ft_strcut(str, 0, start);
	names[1] = ft_strcut(str, start + 1, count);
	names[2] = ft_strcut(str, i, -1);
	value = ft_find_key(names[1]);
	*num = ft_strlen(value);
	ret = ft_super_join(names[0], value, names[2]);
	ft_free_four(names[0], value, names[2], names[1]);
	return (ret);
}

char	*ft_rewrite_dq(char *str)
{
	char	*line[3];
	char	*tmp;
	char	*s;
	int		len;

	line[0] = ft_strcut(str, 0, g_i);
	g_i++;
	len = g_i;
	while (str[g_i] != '"' || (str[g_i - 1] == '\\' && str[g_i] == '"'))
		g_i++;
	line[1] = ft_strcut(str, len, g_i - len);
	tmp = line[1];
	line[1] = ft_address_fun(line[1]);
	ft_fix_mid(line[1]);
	line[2] = ft_strcut(str, g_i + 1, -1);
	s = str;
	str = ft_super_join(line[0], line[1], line[2]);
	ft_free_four(s, line[2], line[0], line[1]);
	g_i -= 2;
	return (str);
}

char	*ft_rewrite_sq(char *str)
{
	char	*first;
	char	*mid;
	char	*last;
	int		len;
	char	*s;

	first = ft_strcut(str, 0, g_i);
	g_i++;
	len = g_i;
	while (str[g_i] != '\'')
		g_i++;
	mid = ft_strcut(str, len, g_i - len);
	last = ft_strcut(str, g_i + 1, -1);
	s = str;
	str = ft_super_join(first, mid, last);
	ft_free_four(s, last, first, mid);
	g_i -= 2;
	return (str);
}

char	*ft_rewrite(char *str1)
{
	char	*str;
	int		len;

	g_i = 0;
	str = NULL;
	len = 0;
	str = ft_strdup(str1);
	while (str[g_i] != '\0')
	{
		if (str[g_i] == '"' && str[g_i - 1] != '\\')
			str = ft_rewrite_dq(str);
		else if (str[g_i] == '\'' && str[g_i - 1] != '\\')
			str = ft_rewrite_sq(str);
		else if (ft_address_test(str))
		{
			len = ft_strlen(str);
			str = ft_address_fun(str);
			g_i += ft_strlen(str) - len;
		}
		else if (str[g_i] == '\\' && str[g_i - 1] != '\\')
			ft_slash(str);
		g_i++;
	}
	return (str);
}
