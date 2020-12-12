/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:24:37 by ayennoui          #+#    #+#             */
/*   Updated: 2019/11/04 17:08:16 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int		size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		j;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = get_size(n);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	j = size - 1;
	if (n <= 0)
	{
		str[0] = n < 0 ? '-' : '0';
		n = -n;
	}
	while (n != 0)
	{
		str[j--] = n % 10 + '0';
		n = n / 10;
	}
	str[size] = '\0';
	return (str);
}
