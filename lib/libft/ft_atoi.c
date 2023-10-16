/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:35:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/16 18:27:45 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long int	_atoi_plus(const char *nptr)
{
	long int	number;

	number = 0;
	while (ft_isdigit(*nptr))
	{
		if ((LONG_MAX / 10) < number)
			return (LONG_MAX);
		if (number == (LONG_MAX / 10) && (*nptr - '0' > LONG_MAX % 10))
			return (LONG_MAX);
		number *= 10;
		number += (*nptr++ - '0');
	}
	return (number);
}

static long int	_atoi_minus(const char *nptr)
{
	long int	number;

	number = 0;
	while (ft_isdigit(*nptr))
	{
		if ((LONG_MIN / 10) > number)
			return (LONG_MIN);
		if (number == (LONG_MIN / 10) && (*nptr - '0' > -(LONG_MIN % 10)))
			return (LONG_MIN);
		number *= 10;
		number -= (*nptr++ - '0');
	}
	return (number);
}

int	ft_atoi(const char *nptr)
{
	bool	minus_flag;

	nptr = ft_skip_charsets(nptr, SPACE_CHARSETS);
	minus_flag = (*nptr == '-');
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (minus_flag)
		return ((int)_atoi_minus(nptr));
	else
		return ((int)_atoi_plus(nptr));
}
