/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:54:58 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/11 16:28:07 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

int		ft_test_pipe(char **com)
{
	int	i;
	int	j;
	int	ex;

	i = 0;
	j = 0;
	ex = 0;
	while (com[i] != NULL)
	{
		j = 0;
		while (com[i][j] == ' ')
			j++;
		if (j == (int)ft_strlen(com[i]))
		{
			ex = 1;
			break ;
		}
		i++;
	}
	if (ex == 1)
		ft_free_double(com);
	return (ex);
}

char	*ft_export_error(char *com)
{
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd(com, 2);
	ft_error_print(" : not a valid identifier\n", 1);
	return (NULL);
}

int		ft_tab_len(t_env *tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i].end == 1)
		i++;
	return (i);
}

int		ft_check_red(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (i > 0 && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
				|| str[i] == ' ' || str[i] == '\f' || str[i] == '\r'))
		i--;
	if (str[i] == '>' || str[i] == '<')
		return (1);
	return (0);
}

char	**ft_find_path(void)
{
	char	**path;
	int		i;

	i = 0;
	while (g_env_tab[i].end && ft_strcmp(g_env_tab[i].key, "PATH"))
		i++;
	if (g_env_tab[i].end == 0)
		return (NULL);
	path = ft_split(g_env_tab[i].value, ':');
	ft_fix_paths(path);
	return (path);
}
