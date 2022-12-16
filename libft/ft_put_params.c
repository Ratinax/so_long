/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:05:41 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/08 14:54:16 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_i(char *s, int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putchar_i(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_i(int n, int fd)
{
	long int	n2;
	long int	div;
	int			res;

	n2 = (long int)n;
	div = 1;
	res = 0;
	if (n == 0)
		return (ft_putchar_i('0', fd));
	if (n == -2147483648)
		return (ft_putstr_i("-2147483648", fd));
	if (n < 0)
		res += ft_putchar_i('-', fd);
	if (n < 0)
		n2 *= -1;
	while (n2 / div > 9)
		div *= 10;
	while (div > 9)
	{
		res += ft_putchar_i(n2 / div + '0', fd);
		n2 -= (n2 / div) * div;
		div /= 10;
	}
	res += ft_putchar_i(n2 / div + '0', fd);
	return (res);
}

int	ft_putunsigned_i(unsigned int n, int fd)
{
	unsigned long int	n2;
	unsigned long int	div;
	int					res;

	n2 = (unsigned long int)n;
	div = 1;
	res = 0;
	if (n == 0)
		return (ft_putchar_i('0', fd));
	while (n2 / div > 9)
		div *= 10;
	while (div > 9)
	{
		res += ft_putchar_i(n2 / div + '0', fd);
		n2 -= (n2 / div) * div;
		div /= 10;
	}
	res += ft_putchar_i(n2 / div + '0', fd);
	return (res);
}

int	ft_puthex_i(unsigned long long nb, int cap, int fd)
{
	char				*str;
	int					res;
	unsigned long long	div;

	div = 1;
	res = 0;
	if (cap)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	while (nb / div > 15)
		div *= 16;
	while (div > 15)
	{
		res += ft_putchar_i(str[nb / div], fd);
		nb = nb % div;
		div /= 16;
	}
	res += ft_putchar_i(str[nb / div], fd);
	return (res);
}
