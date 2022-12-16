/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:36:27 by ratinax           #+#    #+#             */
/*   Updated: 2022/12/13 17:33:24 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**strrdup(char **str)
{
	char	**res;
	int		i;

	i = 0;
	while (str[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = ft_strdup(str[i]);
		if (!res[i])
			return (free_array(res, i), NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}

t_lst_bp	*find_start(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				return (ft_lst_bp_new(i, j));
			j++;
		}
		i++;
	}
	return (NULL);
}

int	nb_directions(char **str, int i, int j)
{
	int	k;

	k = 0;
	if (i <= 0 || j <= 0)
		return (0);
	while (str[k])
		k++;
	k--;
	if (k <= i || j + 1 >= (int)ft_strlen(str[i]))
		return (0);
	return (is_in(str[i + 1][j], "PEC0")
		+ is_in(str[i - 1][j], "PEC0")
		+ is_in(str[i][j + 1], "PEC0")
		+ is_in(str[i][j - 1], "PEC0"));
}

void	ft_test_moove(char **str, int *i, int *j)
{
	if (is_in(str[*i + 1][*j], "EPC0"))
		(*i)++;
	else if (is_in(str[*i - 1][*j], "EPC0"))
		(*i)--;
	else if (is_in(str[*i][*j + 1], "EPC0"))
		(*j)++;
	else if (is_in(str[*i][*j - 1], "EPC0"))
		(*j)--;
}

void	go_to_bp(int *i, int *j, t_lst_bp **bp)
{
	*i = ft_lst_bp_last(*bp)->i;
	*j = ft_lst_bp_last(*bp)->j;
	ft_lst_bp_del_last(bp);
}
