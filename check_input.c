/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:56:24 by ratinax           #+#    #+#             */
/*   Updated: 2022/12/16 15:35:09 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	good_lines(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	good_chars(char **str)
{
	int			i;
	int			j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!is_in(str[i][j], "01CEP"))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	good_amount(char **str)
{
	int			i;
	int			j;
	t_amount	map;

	map.exit = 0;
	map.start = 0;
	map.item = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				map.exit++;
			if (str[i][j] == 'C')
				map.item++;
			if (str[i][j] == 'P')
				map.start++;
			j++;
		}
		i++;
	}
	return ((map.exit == 1) && (map.start == 1) && (map.item >= 1));
}

int	is_surrounded(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[0][i] && str[0][i] == '1')
		i++;
	if (str[0][i] && str[0][i] != '1')
		return (0);
	j = ft_strlen(str[0]);
	i = 0;
	while (str[i] && str[i][0] && (str[i][0] == '1' && str[i][j - 1] == '1'))
		i++;
	if (str[i] && (str[i][0] != '1' || str[i][j - 1] != '1'))
		return (0);
	i--;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	good_input(char **str)
{
	if (ft_strlen(str[0]) <= 3)
		return (0);
	if (!good_lines(str))
		return (0);
	if (!good_chars(str))
		return (0);
	if (!good_amount(str))
		return (0);
	if (!is_surrounded(str))
		return (0);
	return (1);
}
