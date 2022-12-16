/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:35 by ratinax           #+#    #+#             */
/*   Updated: 2022/12/16 14:52:31 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	nb_lines(char *filename)
{
	int		fd;
	char	*tmp;
	int		size;

	fd = open(filename, O_RDONLY);
	tmp = get_next_line(fd);
	size = 1;
	while (tmp)
	{
		size++;
		if (tmp)
			free(tmp);
		tmp = get_next_line(fd);
	}
	if (tmp)
		free(tmp);
	close(fd);
	return (size);
}

char	**get_input(char *filename)
{
	int		fd;
	char	*tmp;
	char	**str;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (ft_putstr_fd(strerror(errno), 2)
			, ft_putstr_fd(": ", 2)
			, ft_putendl_fd(filename, 2), NULL);
	str = malloc(sizeof(char *) * (nb_lines(filename) + 1));
	tmp = get_next_line(fd);
	while (tmp)
	{
		str[i] = ft_strtrim(tmp, "\n");
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	if (i > 0)
		str[i] = tmp;
	if (!tmp && i + 1 < nb_lines(filename) && i > 0)
		return (free_array(str, 1), NULL);
	return (str);
}
