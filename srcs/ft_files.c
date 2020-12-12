/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:55:50 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/07 17:21:03 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_check_file(char *file)
{
	int		fd;
	char	*tmp;

	fd = -1;
	tmp = ft_rewrite(file);
	fd = open(tmp, O_RDONLY);
	close(fd);
	ft_free(tmp);
	if (fd < 0)
		return (0);
	return (1);
}

int		ft_create_file(char *file)
{
	int		fd;
	char	*tmp;

	tmp = ft_rewrite(file);
	fd = open(tmp, O_CREAT, 0666);
	ft_free(tmp);
	close(fd);
	return (0);
}
