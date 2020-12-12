/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:41:59 by ayennoui          #+#    #+#             */
/*   Updated: 2019/11/04 16:54:02 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l_s;
	size_t	len;

	if (!dst && !src)
		return (0);
	l_s = ft_strlen(src);
	if (size)
	{
		len = (l_s >= size) ? size - 1 : l_s;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (l_s);
}
