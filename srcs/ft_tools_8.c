/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:06:16 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/09 19:22:31 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

char	*ft_address_fun(char *str)
{
	int		i;
	int		num;
	char	*s1;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i - 1] != '\\' && (ft_isalnum(str[i + 1])
		|| str[i + 1] == '?' || str[i + 1] == '"' || str[i + 1] == '\''))
		{
			s1 = str;
			str = ft_addr(str, i, &num);
			if (ft_strlen(str) != ft_strlen(s1))
				free(s1);
			i += num;
			i--;
		}
		i++;
	}
	return (str);
}
