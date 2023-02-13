/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:00:33 by afindo          #+#    #+#             */
/*   Updated: 2022/02/24 17:55:59 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		write (1, "(null)", 6);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int i, int base)
{
	char	*base_set;
	int		count;
	int		n;

	base_set = "0123456789abcdef";
	count = 0;
	n = i % base;
	if (i / base > 0)
		count += ft_putnbr(i / base, base);
	count += ft_putchar(base_set[n]);
	return (count);
}

int	ft_putint(int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	count += ft_putnbr(i, 10);
	return (count);
}

int	ft_print(char *string, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if (string[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if (string[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (count);
}
