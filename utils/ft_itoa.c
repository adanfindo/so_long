/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:18:10 by afindo          #+#    #+#             */
/*   Updated: 2022/02/24 17:55:57 by afindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

size_t	numlen(int n)
{
	size_t	num;

	num = 0;
	if (n == 0)
		num++;
	while (n)
	{
		n = n / 10;
		num++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char		*strnum;
	size_t		nlen;
	size_t		number;

	number = n;
	nlen = numlen(n);
	if (n < 0)
	{
		number = number * -1;
		nlen++;
	}
	strnum = (char *)malloc(sizeof(char) * (nlen + 1));
	if (strnum == NULL)
		return (NULL);
	*(strnum + nlen) = '\0';
	while (nlen--)
	{
		*(strnum + nlen) = number % 10 + '0';
		number = number / 10;
	}
	if (n < 0)
		*(strnum + 0) = '-';
	return (strnum);
}
