/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:41:44 by ratinax           #+#    #+#             */
/*   Updated: 2022/12/16 14:51:39 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_a_good_path(char **str, t_lst_bp **bp)
{
	int	i;
	int	j;

	i = (*bp)->i;
	j = (*bp)->j;
	ft_lst_bp_del_last(bp);
	while (str[i][j] != 'E')
	{
		str[i][j] = '2';
		if (nb_directions(str, i, j) == 0)
		{
			if (ft_lst_bp_last(*bp))
				go_to_bp(&i, &j, bp);
			else
				return (0);
		}
		else
		{
			if (nb_directions(str, i, j) > 1)
				ft_lst_bp_add_back(bp, ft_lst_bp_new(i, j));
			ft_test_moove(str, &i, &j);
		}
	}
	return (1);
}

int	amount_collectibles(char **str)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	is_all_collectibles(char **str, t_lst_bp **bp, int amount)
{
	int	i;
	int	j;

	i = (*bp)->i;
	j = (*bp)->j;
	ft_lst_bp_del_last(bp);
	while (amount > 0)
	{
		amount -= (str[i][j] == 'C');
		str[i][j] = '2';
		if (nb_directions(str, i, j) == 0 && amount > 0)
		{
			if (ft_lst_bp_last(*bp))
				go_to_bp(&i, &j, bp);
			else
				return (0);
		}
		else
		{
			if (nb_directions(str, i, j) > 1)
				ft_lst_bp_add_back(bp, ft_lst_bp_new(i, j));
			ft_test_moove(str, &i, &j);
		}
	}
	return (1);
}

int	is_path(char **str)
{
	t_lst_bp	*bp;
	char		**str2;
	int			res;

	bp = NULL;
	str2 = strrdup(str);
	if (!str2)
		return (0);
	bp = find_start(str2);
	if (!bp)
		return (free_array(str2, 1), 0);
	res = is_a_good_path(str2, &bp);
	free_array(str2, 1);
	ft_lst_bp_clear(&bp);
	bp = NULL;
	str2 = strrdup(str);
	if (!str2)
		return (0);
	bp = find_start(str2);
	if (!bp)
		return (free_array(str2, 1), 0);
	res *= is_all_collectibles(str2, &bp, amount_collectibles(str));
	ft_lst_bp_clear(&bp);
	return (free_array(str2, 1), res);
}
