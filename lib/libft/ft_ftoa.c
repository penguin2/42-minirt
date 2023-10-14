/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:12:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/14 18:15:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	_fill_decimal(char *str, double number, size_t limit)
{
	*str++ = '.';
	while (0 < limit)
	{
		number -= (long long int)number;
		number *= 10;
		if (number < 0)
			*str++ = (-(int)number % 10) + '0';
		else
			*str++ = ((int)number % 10) + '0';
		limit--;
	}
}

char	*_ftoa_plus(double number, size_t limit)
{
	char	*str_integer;
	char	*str;
	size_t	idx;

	idx = ft_count_digit(number);
	str_integer = ft_lltoa((long long int)number);
	if (limit == idx)
		return (str_integer);
	str = (char *)ft_xcalloc(limit + 2, sizeof(char));
	ft_strlcpy(str, str_integer, idx + 1);
	free(str_integer);
	_fill_decimal(&str[idx], number, limit - idx);
	return (str);
}

char	*_ftoa_minus(double number, size_t limit)
{
	char	*str_integer;
	char	*str;
	size_t	idx;

	idx = ft_count_digit(number);
	str_integer = ft_lltoa((long long int)number);
	if (limit == idx)
		return (str_integer);
	str = (char *)ft_xcalloc(limit + 3, sizeof(char));
	if (str_integer[0] == '-')
		ft_strlcpy(str, str_integer, idx + 2);
	else
	{
		str[0] = '-';
		ft_strlcpy(&str[1], str_integer, idx + 1);
	}
	free(str_integer);
	_fill_decimal(&str[idx + 1], number, limit - idx);
	return (str);
}

char	*ft_ftoa(double number, size_t limit)
{
	if (limit < ft_count_digit((long long int)number))
		return (NULL);
	else if (number < 0)
		return (_ftoa_minus(number, limit));
	else
		return (_ftoa_plus(number, limit));
}
