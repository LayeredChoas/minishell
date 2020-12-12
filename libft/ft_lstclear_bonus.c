/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:19:44 by ayennoui          #+#    #+#             */
/*   Updated: 2019/11/04 18:49:49 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *new;
	t_list *new1;

	if (lst)
	{
		new = *lst;
		while (new != NULL)
		{
			new1 = new->next;
			(*del)(new->content);
			free(new);
			new = new1;
		}
		*lst = NULL;
	}
}
