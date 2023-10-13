/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:48:14 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 15:25:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

size_t	_get_digit(long int n)
{
	size_t	counter;

	if (-10 < n && n < 10)
		return (1);
	n /= 10;
	if (n < 0)
		n = -n;
	counter = 1;
	while (0 < n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

long int	_get_div_number(size_t digit)
{
	long int	number;

	if (digit <= 1)
		return (1);
	number = 1;
	while (0 < --digit)
		number *= 10;
	return (number);
}

void	_fill_str_long(char *str, long int n)
{
	long int	div_number;
	size_t		digit;

	digit = _get_digit(n);
	while (digit != 0)
	{
		div_number = _get_div_number(digit--);
		if (n < 0)
			*str++ = -((n / div_number) % 10) + '0';
		else
			*str++ = ((n / div_number) % 10) + '0';
	}
}

char	*ft_ltoa(long int n)
{
	char	*str;
	bool	minus_flag;

	minus_flag = (n < 0);
	str = (char *)ft_xcalloc(_get_digit(n) + minus_flag + 1, sizeof(char));
	if (minus_flag)
	{
		*str = '-';
		_fill_str_long(&str[1], n);
	}
	else
		_fill_str_long(str, n);
	return (str);
}
