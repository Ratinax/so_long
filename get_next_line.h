/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:06:21 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/12 13:32:58 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	update_buff(char buffer[]);
char	*ft_strjoin2(char *s1, char *s2);
void	ft_bzero2(void *s, size_t n);
void	*ft_memmove2(void *dst, const void *src, size_t len);
char	*ft_strdup2(const char *s1);
size_t	ft_strlen2(const char *s);
int		is_in2(char c, char *str);

#endif
