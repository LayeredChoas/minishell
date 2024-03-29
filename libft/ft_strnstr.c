/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:46:14 by ayennoui          #+#    #+#             */
/*   Updated: 2019/11/12 16:23:45 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const	char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (len == 0 && !haystack)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && needle[j])
	{
		j = 0;
		while (haystack[i + j] == needle[j] &&
				haystack[i + j] && needle[j] && i + j < len)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		else
			i++;
	}
	return (NULL);
}
