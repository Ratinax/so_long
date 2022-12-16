/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:39:17 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/13 13:45:12 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			result++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (result);
}

unsigned int	start_word(char const *s, char c, int ind)
{
	unsigned int	i;

	i = 0;
	while (s[i] == c)
		i++;
	if (ind == 0)
		return (i);
	while (s[i])
	{
		if (s[i] == c)
		{
			ind--;
			while (s[i] == c)
				i++;
		}
		if (ind == 0)
			return (i);
		i++;
	}
	return (-1);
}

size_t	size_word(char const *s, char c, int ind)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			ind--;
			while (s[i] == c)
				i++;
		}
		while (s[i] && s[i] != c && ind == 0)
		{
			i++;
			j++;
		}
		if (ind == 0)
			return (j);
		i++;
	}
	return (-1);
}

void	free_array(char **astring, int n)
{
	int	i;

	i = 0;
	if (!astring)
		return ;
	while (i < n || astring[i])
	{
		free(astring[i]);
		i++;
	}
	free(astring);
}

char	**ft_split(char const *s, char c)
{
	char	**astring;
	int		nb_words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	astring = malloc(sizeof(char *) * (nb_words + 1));
	if (!astring)
		return (NULL);
	while (i < nb_words)
	{
		astring[i] = ft_substr(s, start_word(s, c, i), size_word(s, c, i));
		if (!astring[i])
		{
			free_array(astring, i + 1);
			return (NULL);
		}
		i++;
	}
	astring[i] = NULL;
	return (astring);
}
