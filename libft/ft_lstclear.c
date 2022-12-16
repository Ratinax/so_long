/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:09:18 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/13 11:03:17 by tibernot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (!lst)
		return ;
	elem = *lst;
	while (*lst)
	{
		elem = (*lst)->next;
		if (del)
			ft_lstdelone(*lst, del);
		*lst = elem;
	}
	*lst = NULL;
}
