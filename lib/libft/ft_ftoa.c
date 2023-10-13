/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:12:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/16 21:50:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	_fill_decimal(char *str, double number, size_t limit)
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

static char	*_ftoa_plus(double number, size_t limit)
{
	char	*str_integer;
	char	*str;
	size_t	cnt;

	cnt = ft_count_digit((long long int)number);
	str_integer = ft_lltoa((long long int)number);
	if (limit == cnt)
		return (str_integer);
	str = (char *)ft_xcalloc(limit + 2, sizeof(char));
	ft_strlcpy(str, str_integer, limit + 2);
	free(str_integer);
	_fill_decimal(&str[cnt], number, limit - cnt);
	return (str);
}

static char	*_ftoa_minus(double number, size_t limit)
{
	char	*str_plus;
	char	*str;

	number = -number;
	str_plus = _ftoa_plus(number, limit);
	str = (char *)ft_xcalloc(limit + 3, sizeof(char));
	str[0] = '-';
	ft_strlcpy(&str[1], str_plus, limit + 2);
	free(str_plus);
	return (str);
}

/**
* @brief Convert double type to char * type with limited number of digits
*
* @param number Target to be converted to string
* @param limit Value less than or equal to the number of digits in LLONG_MAX
* 
* @return String limited to the number of digits specified by limit
*/
char	*ft_ftoa(double number, size_t limit)
{
	if (limit < ft_count_digit((long long int)number))
		return (NULL);
	else if (number < 0)
		return (_ftoa_minus(number, limit));
	else
		return (_ftoa_plus(number, limit));
}
// #include <stdio.h>
// void	test(double n, size_t limit)
// {
// 	printf("n = %.15f str = %s\n", n, ft_ftoa(n, limit));
// }
// int main(void)
// {
// 	test(-1, 15);
// 	test(-1.1111111, 15);
// 	test(1.1111111, 15);
// 	test(-13232.1111111, 15);
// 	test(13232.1111111, 15);
// 	test(0.1111111, 15);
// 	test(-0.111111, 15);
// 	return (0);
// }
