/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:06:23 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/12 13:34:24 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_in2(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			res;

	tmp = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (ft_bzero2(buffer, BUFFER_SIZE), NULL);
	if (buffer[0])
		tmp = ft_strjoin2(tmp, buffer);
	while (!is_in2('\n', buffer))
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res <= 0)
			return (update_buff(buffer), tmp);
		if (res < BUFFER_SIZE)
		{
			ft_bzero2(buffer + res, ft_strlen2(buffer + res));
			tmp = ft_strjoin2(tmp, buffer);
			return (update_buff(buffer), tmp);
		}
		tmp = ft_strjoin2(tmp, buffer);
		if (!is_in2('\n', buffer))
			update_buff(buffer);
	}
	return (update_buff(buffer), tmp);
}
