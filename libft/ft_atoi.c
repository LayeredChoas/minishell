/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:56:40 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/16 19:22:02 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_skip_space(const char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	return (i);
}

long long		ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	num;

	num = 0;
	sign = 1;
	i = 0;
	i += ft_skip_space(str);
	if (str[i] == '+' || str[i] == '-')
	{
		(str[i] == '-') ? sign = -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num < 0)
			return (-1);
		if (sign == -1 && num < 0)
			return (0);
		i++;
	}
	return (num * sign);
}
