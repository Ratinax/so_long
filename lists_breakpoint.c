/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_breakpoint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:06:41 by ratinax           #+#    #+#             */
/*   Updated: 2022/12/16 14:53:28 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lst_bp_del_last(t_lst_bp **lst)
{
	t_lst_bp	*tmp;
	t_lst_bp	*tmp2;

	if (!lst)
		return ;
	if (!(*lst))
		return ;
	if (!(*lst)->next)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	if (tmp2)
	{
		free(tmp2);
		tmp2 = NULL;
	}
	if (tmp)
		tmp->next = NULL;
}

t_lst_bp	*ft_lst_bp_last(t_lst_bp *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_bp_add_back(t_lst_bp **lst, t_lst_bp *new)
{
	t_lst_bp	*elem;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	elem = ft_lst_bp_last(*lst);
	elem->next = new;
}

t_lst_bp	*ft_lst_bp_new(int i, int j)
{
	t_lst_bp	*res;

	res = malloc(sizeof(t_lst_bp));
	if (!res)
		return (NULL);
	res->i = i;
	res->j = j;
	res->next = NULL;
	return (res);
}

void	ft_lst_bp_clear(t_lst_bp **lst)
{
	t_lst_bp	*elem;

	if (!lst)
		return ;
	elem = *lst;
	while (*lst)
	{
		elem = (*lst)->next;
		free(*lst);
		*lst = elem;
	}
	*lst = NULL;
	lst = NULL;
}
