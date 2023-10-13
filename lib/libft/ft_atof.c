/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:43:32 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 16:36:12 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	_atof_integer(const char *nptr, bool minus_flag)
{
	double	number;

	number = 0.0;
	while (ft_isdigit(*nptr))
	{
		number *= 10.0;
		if (minus_flag)
			number -= (*nptr - '0');
		else
			number += (*nptr - '0');
		nptr++;
	}
	return (number);
}

static double	_atof_decimal(const char *nptr, bool minus_flag)
{
	double	number;
	double	tmp;

	number = 0.0;
	tmp = 1.0;
	while (ft_isdigit(*nptr))
	{
		tmp *= 0.1;
		if (minus_flag)
			number -= (tmp * (*nptr - '0'));
		else
			number += (tmp * (*nptr - '0'));
		nptr++;
	}
	return (number);
}

double	ft_atof(const char *nptr)
{
	double	number;
	bool	minus_flag;

	nptr = ft_skip_charsets(nptr, "\t\n\r\v\f ");
	minus_flag = (*nptr == '-');
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	number = _atof_integer(nptr, minus_flag);
	nptr = ft_strchr(nptr, '.');
	if (nptr == NULL)
		return (number);
	else
		return (number + _atof_decimal(nptr + 1, minus_flag));
}
