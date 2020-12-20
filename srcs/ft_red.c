/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:44:56 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/19 12:14:59 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_red_out(char *str, int start)
{
	int		i;
	char	*tmp;
	char	**cmd;
	int		ap;
	char	*out;

	ap = 0;
	i = start;
	if (g_red.cmd == NULL)
		g_red.cmd = ft_strcut(str, 0, start - 1);
	(str[i] == '>') ? i++ : 1;
	ap = i;
	while (str[i] != '\0' && str[i] != '<' && str[i] != '>')
		i++;
	if (i == ap)
		return (0);
	tmp = ft_strcut(str, ap, i - ap);
	cmd = ft_adv_split(tmp, ' ');
	ft_red_out_1(cmd);
	out = ft_rewrite(cmd[0]);
	ft_red_out_app(ap, start, out);
	ft_free_double(cmd);
	ft_free(tmp);
	free(out);
	return (i - start);
}

int		ft_red_in(char *str, int start)
{
	int		i;
	char	*tmp;
	char	**cmd;

	if (g_red.cmd == NULL)
		g_red.cmd = ft_strcut(str, 0, start - 1);
	i = start;
	while (str[i] != '\0' && str[i] != '<' && str[i] != '>')
		i++;
	if (i == start)
		return (0);
	tmp = ft_strcut(str, start, i - start);
	cmd = ft_adv_split(tmp, ' ');
	ft_red_in_1(cmd);
	ft_free_double(cmd);
	ft_free(tmp);
	return (i - start);
}

void	ft_red_setup(char *str)
{
	int i;
	int start;

	i = 0;
	start = 0;
	while (str[i] != '\0')
	{
		start = i;
		if (str[i] == '"')
			i += ft_skip_q(&str[i + 1], '"');
		else if (str[i] == '\'')
			i += ft_skip_q(&str[i + 1], '\'');
		else if (str[i] == '>')
			i += ft_red_out(str, i + 1);
		else if (str[i] == '<')
			i += ft_red_in(str, i + 1);
		if ((str[start] == '>' || str[start] == '<') && start == i)
		{
			ft_error_print(g_syntax_red, 2);
			g_file_error = 127;
			break ;
		}
		i++;
	}
}

void	ft_in_out_test(void)
{
	if (g_red.in != g_in)
	{
		dup2(g_red.in, 0);
		close(g_red.in);
	}
	if (g_red.out != g_out)
	{
		dup2(g_red.out, 1);
		close(g_red.out);
	}
}

void	ft_red_fun(char *str)
{
	char	*tmp;

	g_file_error = 0;
	ft_red_setup(str);
	if (g_file_error != 0)
	{
		ft_free(g_red.cmd);
		return ;
	}
	if (g_red.cmd == NULL)
		ft_options(str);
	else
	{
		ft_in_out_test();
		tmp = ft_super_join(g_red.cmd, " ", g_red.arg);
		free(g_red.cmd);
		free(g_red.arg);
		g_red.cmd = NULL;
		g_red.arg = ft_strdup("");
		ft_options(tmp);
		ft_free(tmp);
		g_red.out = g_out;
		g_red.in = g_in;
	}
}
