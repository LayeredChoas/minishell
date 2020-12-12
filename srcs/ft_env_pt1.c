/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_pt1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:43:59 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/06 19:59:08 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

void	ft_update_back(char *key)
{
	int		i;

	i = 0;
	while (g_env_back[i] != NULL)
	{
		if (ft_strcmp(g_env_back[i], key) == 0)
		{
			free(g_env_back[i]);
			g_env_back[i] = ft_strdup(".");
			break ;
		}
		i++;
	}
}

int		ft_check_tab(char **tab, char *add)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != '\0')
	{
		if (ft_strcmp(tab[i], add) == 0)
			return (1);
		i++;
	}
	return (0);
}
