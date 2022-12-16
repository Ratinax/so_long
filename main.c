/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:55:25 by ratinax           #+#    #+#             */
/*   Updated: 2022/12/16 14:53:32 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	good_file_name(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) < 4)
	{
		ft_putstr_fd("Wrong extension file", 2);
		ft_putstr_fd(", supposed to be a .ber: ", 2);
		ft_putendl_fd(str, 2);
		return (0);
	}
	if (str[ft_strlen(str) - 1] != 'r'
		|| str[ft_strlen(str) - 2] != 'e'
		|| str[ft_strlen(str) - 3] != 'b'
		|| str[ft_strlen(str) - 4] != '.')
	{
		ft_putstr_fd("Wrong extension file", 2);
		ft_putstr_fd(", supposed to be a .ber: ", 2);
		ft_putendl_fd(str, 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char		**str;

	str = NULL;
	if (argc != 2)
		return (ft_putendl_fd("Not good amount of parameters", 2), 1);
	if (!good_file_name(argv[1]))
		return (1);
	str = get_input(argv[1]);
	if (!str)
		return (1);
	if (!good_input(str) || !is_path(str))
		return (free_array(str, 1), ft_putendl_fd("Error", 2), 1);
	game(str);
	free_array(str, 1);
	exit(0);
	return (0);
}
