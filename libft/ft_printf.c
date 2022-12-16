/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:37:11 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/12 13:34:59 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in(char c, char *str)
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

int	put_params(char c, va_list *args)
{
	if (c == '%')
		return (ft_putchar_i('%', 1));
	else if (c == 'c')
		return (ft_putchar_i(va_arg(*args, int), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_i(va_arg(*args, int), 1));
	else if (c == 's')
		return (ft_putstr_i(va_arg(*args, char *), 1));
	else if (c == 'u')
		return (ft_putunsigned_i(va_arg(*args, unsigned int), 1));
	else if (c == 'X')
		return (ft_puthex_i(va_arg(*args, unsigned int), 1, 1));
	else if (c == 'x')
		return (ft_puthex_i(va_arg(*args, unsigned int), 0, 1));
	else if (c == 'p')
		return (ft_putstr_i("0x", 1)
			+ ft_puthex_i(va_arg(*args, unsigned long long), 0, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	liste;

	i = 0;
	res = 0;
	va_start(liste, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && is_in(str[i + 1], "cspdiuxX%"))
		{
			res += put_params(str[i + 1], &liste);
			i++;
		}
		else if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			res++;
		}
		else if (str[i] == '%')
			i++;
		i++;
	}
	va_end(liste);
	return (res);
}
