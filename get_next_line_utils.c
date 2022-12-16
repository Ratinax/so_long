/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:06:22 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/12 13:34:08 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup2(const char *s1)
{
	char	*pt;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	pt = malloc(sizeof(char) * (i + 1));
	if (!(pt))
		return (0);
	i = 0;
	while (s1[i])
	{
		pt[i] = ((char *)s1)[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}

void	*ft_memmove2(void *dst, const void *src, size_t len)
{
	unsigned char	*pt;
	size_t			i;

	pt = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src && src < dst + len)
	{
		while (i < len)
		{
			pt[i] = ((unsigned char *)src)[i];
			i++;
		}
		pt[i] = '\0';
	}
	else
	{
		while (len--)
			pt[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}

void	ft_bzero2(void *s, size_t n)
{
	unsigned char	*pt;
	size_t			i;

	pt = s;
	i = 0;
	while (i < n)
	{
		pt[i] = 0;
		i++;
	}
}

void	update_buff(char buffer[])
{
	int	i;
	int	size_bufferi;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		ft_bzero2(buffer, BUFFER_SIZE);
		return ;
	}
	else
	{
		size_bufferi = ft_strlen2(buffer + i + 1);
		ft_memmove2(buffer, buffer + i + 1, ft_strlen2(buffer + i + 1));
		buffer[size_bufferi] = '\0';
	}
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		sizes1;

	sizes1 = ft_strlen2(s1);
	s3 = malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!s3)
		return (free(s1), NULL);
	i = -1;
	while (s1 && s1[++i])
		s3[i] = s1[i];
	i = 0;
	while (s2 && s2[i] && s2[i] != '\n')
	{
		s3[i + sizes1] = s2[i];
		i++;
	}
	if (s2)
		s3[i + sizes1] = s2[i];
	if (s2 && s2[i] == '\n')
		s3[i + sizes1 + 1] = '\0';
	if (s1)
		free(s1);
	return (s3);
}
