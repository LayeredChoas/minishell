/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:07:38 by ayennoui          #+#    #+#             */
/*   Updated: 2019/10/20 13:43:29 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		place;
	int		i;

	i = 0;
	place = 0;
	if (s[i] == (char)c)
		return ((char*)s);
	if (s[i] == '\0' && (char)c == '\0')
		return ((char*)&s[i]);
	if (s[i] == '\0' && (char)c != '\0')
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			place = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)&s[i]);
	if (place != 0)
		return ((char*)&s[place]);
	return (NULL);
}
