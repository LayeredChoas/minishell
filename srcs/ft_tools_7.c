/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:03:49 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/07 20:48:59 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_red_out_1(char **cmd)
{
	ft_create_file(cmd[0]);
	ft_args_add(cmd);
	if (g_red.out != g_out)
		close(g_red.out);
}

int		ft_address_test(char *str)
{
	if (str[g_i] == '$' && str[g_i - 1] != '\\' && (ft_isalnum(str[g_i + 1])
	|| str[g_i + 1] == '?' || str[g_i + 1] == '"' || str[g_i + 1] == '\''))
		return (1);
	return (0);
}

void	ft_free_four(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		ft_free(s1);
	if (s2)
		ft_free(s2);
	if (s3)
		ft_free(s3);
	if (s4)
		ft_free(s4);
}

void	ft_red_out_app(int ap, int start, char *out)
{
	if (ap != start)
		g_red.out = open(out, O_WRONLY | O_APPEND);
	else
		g_red.out = open(out, O_WRONLY | O_TRUNC);
}

void	ft_red_in_1(char **cmd)
{
	char *in;

	in = NULL;
	if (ft_check_file(cmd[0]))
	{
		if (g_red.in != g_in)
			close(g_red.in);
		ft_args_add(cmd);
		in = ft_rewrite(cmd[0]);
		g_red.in = open(in, O_RDONLY, 0666);
		free(in);
	}
	else
	{
		ft_error_print("Error file doesn't exist\n", 1);
		g_file_error = 127;
	}
}
