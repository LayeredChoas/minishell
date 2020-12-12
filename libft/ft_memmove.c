/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:53:34 by ayennoui          #+#    #+#             */
/*   Updated: 2019/11/04 16:52:39 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	int				i;

	if (!src && !dst)
		return (NULL);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = (int)len - 1;
	if (src < dst)
	{
		while (i >= 0)
		{
			dst1[i] = src1[i];
			i--;
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
