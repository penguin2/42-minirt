/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:48:14 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/14 18:00:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	_fill_str_long(char *str, long long int n)
{
	long long int	div_number;
	size_t			digit;

	digit = ft_count_digit(n);
	while (digit != 0)
	{
		div_number = _get_div_number(digit--);
		if (n < 0)
			*str++ = -((n / div_number) % 10) + '0';
		else
			*str++ = ((n / div_number) % 10) + '0';
	}
}

char	*ft_lltoa(long long int n)
{
	char	*str;
	bool	minus_flag;

	minus_flag = (n < 0);
	str = (char *)ft_xcalloc(ft_count_digit(n) + minus_flag + 1, sizeof(char));
	if (minus_flag)
	{
		*str = '-';
		_fill_str_long(&str[1], n);
	}
	else
		_fill_str_long(str, n);
	return (str);
}
