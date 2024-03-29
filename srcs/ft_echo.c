/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:40:12 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/19 11:39:31 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_slash_n(char *str)
{
	int i;
	int qt;

	qt = 0;
	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-' && str[i + 1] == 'n')
	{
		i++;
		while (str[i] == 'n')
			i++;
		if (str[i] != '\0')
			return (0);
		return (1);
	}
	return (0);
}

void	ft_echo(char **str)
{
	int i;
	int newline;

	newline = 0;
	i = 0;
	g_fail = 0;
	while (str[i] != NULL && ft_slash_n(str[i]) == 1)
		i++;
	newline = i;
	while (str[i] != NULL)
	{
		ft_putstr(str[i]);
		(str[i + 1] != NULL) ? ft_putchar(' ') : 1;
		i++;
	}
	(newline == 0) ? ft_putchar('\n') : 1;
}
