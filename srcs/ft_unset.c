/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:06:08 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/16 17:48:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_unset_export(char **com)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (com[i] != NULL)
	{
		ft_update_back(com[i]);
		i++;
	}
}

void	ft_unset(char **com)
{
	int i;
	int j;

	j = 0;
	i = 0;
	g_fail = 0;
	ft_unset_export(com);
	while (com[i] != NULL)
	{
		j = 0;
		while (g_env_tab[j].end)
		{
			if (ft_strcmp(com[i], g_env_tab[j].key) == 0)
				g_env_tab = ft_remove_tab(g_env_tab, com[i]);
			j++;
		}
		i++;
	}
}
