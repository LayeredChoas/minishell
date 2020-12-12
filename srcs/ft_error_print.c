/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:34:51 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/07 17:31:01 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_add_dq(char *str)
{
	int i;

	i = 1;
	while (str[i] != '\0' && (str[i] != '"' ||
	(str[i] == '"' && str[i - 1] == '\\')))
		i++;
	return (i);
}

int		ft_add_sq(char *str)
{
	int i;

	i = 1;
	while (str[i] != '\0' && str[i] != '\'')
		i++;
	return (i);
}

int		ft_check_errors_global(char *str)
{
	int i;
	int t;

	t = 0;
	i = 0;
	if (str[ft_strlen(str) - 1] == '\\' && str[ft_strlen(str) - 2] != '\\')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '"' && str[i - 1] != '\\')
		{
			i += ft_add_dq(&str[i]);
			if (str[i] != '"')
				return (1);
		}
		else if (str[i] == '\'')
		{
			i += ft_add_sq(&str[i]);
			if (str[i] != '\'')
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_free_double(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int		ft_error_print(char *str, int ret)
{
	ft_putstr_fd(str, 2);
	g_fail = 127;
	if (ret == 2)
		g_fail = ret;
	if (g_pp)
		exit(ret);
	return (0);
}
