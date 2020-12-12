/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:36:06 by ayennoui          #+#    #+#             */
/*   Updated: 2019/11/02 15:00:57 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_d;
	size_t	l_s;
	size_t	j;
	size_t	i;

	if (size == 0 && !dst)
		return (0);
	l_d = ft_strlen(dst);
	l_s = ft_strlen(src);
	if (size <= l_d)
		return (l_s + size);
	else
		l_s += l_d;
	i = 0;
	j = l_d;
	while (src[i] && i < size - l_d - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (l_s);
}
