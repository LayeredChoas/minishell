/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:40:57 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/16 19:44:54 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_exit_num(char *com)
{
	long long x;

	x = ft_atoi(com);
	if (x < 0 && com[0] != '-')
	{
		ft_putstr_fd(com, 2);
		ft_error_print(": numeric argument required\n", 2);
		exit(2);
	}
	if (x >= 0 && com[0] == '-')
	{
		ft_putstr_fd(com, 2);
		ft_error_print(": numeric argument required\n", 2);
		exit(2);
	}
	exit(x);
}

void	ft_exit(char **com)
{
	int i;

	i = 0;
	ft_putstr("exit\n");
	if (com[0] == NULL)
	{
		g_exit = 1;
		exit(0);
	}
	while (com[0][i] != '\0')
	{
		if (ft_isdigit(com[0][i]) == 0 && com[0][0] != '-')
			break ;
		i++;
	}
	if (i != (int)ft_strlen(com[0]))
	{
		ft_putstr_fd(com[0], 2);
		ft_error_print(": numeric argument required\n", 2);
		exit(2);
	}
	g_exit = 1;
	ft_exit_num(com[0]);
}
