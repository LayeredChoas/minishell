/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:07:24 by ayennoui          #+#    #+#             */
/*   Updated: 2019/11/04 18:53:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*new;

	if (!lst)
		return (0);
	new = lst;
	i = 1;
	while (new->next != NULL)
	{
		new = new->next;
		i++;
	}
	return (i);
}
