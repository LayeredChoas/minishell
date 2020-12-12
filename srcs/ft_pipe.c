/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:42:18 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/09 20:00:52 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_pipe_fork(int out, int fds[2], char *str)
{
	if (g_fork_id != 0)
		g_fork_work = g_fork_id;
	g_fork_id = fork();
	if (g_fork_id != 0)
	{
		if (g_fork_work)
			wait(NULL);
		dup2(out, 1);
		close(out);
		close(fds[1]);
	}
	else
	{
		close(fds[0]);
		close(fds[1]);
		ft_red_fun(str);
	}
}

int		ft_pipe_f(int fd, char *str)
{
	int fds[2];
	int out;
	int status;

	status = 0;
	out = dup(1);
	pipe(fds);
	if (fd != -1)
	{
		dup2(fd, 0);
		close(fd);
	}
	dup2(fds[1], 1);
	ft_pipe_fork(out, fds, str);
	if (status)
		g_fail = ft_status_num(status);
	dup2(out, 1);
	close(out);
	return (fds[0]);
}

void	ft_pipe_l(int fd, char *str)
{
	int id;
	int status;

	status = 0;
	id = 0;
	if (fd != -1)
	{
		dup2(fd, 0);
		close(fd);
	}
	id = fork();
	if (id != 0)
	{
		if (g_fork_id != 0)
		{
			waitpid(id, &status, 0);
			g_fail = ft_status_num(status);
			kill(g_fork_id, SIGKILL);
		}
		wait(&status);
	}
	else
		ft_red_fun(str);
	if (status && g_fork_id == 0)
		g_fail = ft_status_num(status);
}

void	ft_pipe_loop(char **com)
{
	int i;
	int fd;

	i = 0;
	fd = -1;
	while (com[i] != NULL && g_pp == 1)
	{
		if (com[i + 1] != NULL)
			fd = ft_pipe_f(fd, com[i]);
		else
			ft_pipe_l(fd, com[i]);
		i++;
	}
}

void	ft_pipe(char *str)
{
	char **com;

	com = NULL;
	g_fork_work = 0;
	g_fork_id = 0;
	if (!(com = ft_adv_split(str, '|')))
		return ;
	if (com[1] == NULL)
	{
		g_pp = 0;
		ft_red_fun(com[0]);
	}
	if (ft_test_pipe(com) == 1)
	{
		ft_putstr_fd(g_syntax_pipe, 2);
		g_fail = 2;
		return ;
	}
	ft_pipe_loop(com);
	ft_free_double(com);
}
