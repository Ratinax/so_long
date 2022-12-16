/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:44:32 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/13 10:58:21 by tibernot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	int		lstsize;

	if (!lst || !f)
		return (NULL);
	lstsize = ft_lstsize(lst);
	res = NULL;
	while (lst)
	{
		ft_lstadd_back(&res, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	if (lstsize != ft_lstsize(res))
	{
		ft_lstclear(&res, del);
		return (NULL);
	}
	return (res);
}
