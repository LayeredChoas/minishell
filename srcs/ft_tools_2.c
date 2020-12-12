/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:51:18 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/07 20:40:48 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

char	*ft_first_add(char *ret, char *s1)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

char	*ft_super_join(char *s1, char *s2, char *s3)
{
	char	*ret;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	ret = NULL;
	ret = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	ret = ft_first_add(ret, s1);
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	j = 0;
	while (s3[j] != '\0')
	{
		ret[i] = s3[j];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_args_add(char **cmd)
{
	int		i;
	char	*tmp;

	i = 1;
	if (cmd[i] == NULL)
		return ;
	while (cmd[i] != NULL)
	{
		tmp = g_red.arg;
		g_red.arg = ft_super_join(g_red.arg, " ", cmd[i]);
		ft_free(tmp);
		i++;
	}
}
