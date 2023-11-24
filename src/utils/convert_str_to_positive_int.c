/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str_to_positive_int.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:56:56 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 21:08:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include <limits.h>
#include <stdbool.h>

static bool	_is_all_digit(const char *str);
static int	_convert_with_upperbound(const char *str, int *val, int upperbound);

int	convert_str_to_positive_int(const char *str, int *val)
{
	if (!_is_all_digit(str))
		return (ERROR);
	return (_convert_with_upperbound(str, val, INT_MAX));
}

static bool	_is_all_digit(const char *str)
{
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (false);
		++str;
	}
	return (true);
}

static int	_convert_with_upperbound(const char *str, int *val, int upperbound)
{
	int	x;
	int	digit;

	x = 0;
	while (*str != '\0')
	{
		digit = *str - '0';
		if ((upperbound - digit) / 10 < x)
			return (ERROR);
		x = x * 10 + digit;
		++str;
	}
	*val = x;
	return (SUCCESS);
}
