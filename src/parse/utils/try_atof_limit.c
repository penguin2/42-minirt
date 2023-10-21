/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_atof_limit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:24:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 15:49:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"

static const char	*_skip_digit(const char *nptr, size_t *limit)
{
	while (ft_isdigit(*nptr) && 0 < *limit)
	{
		nptr++;
		*limit -= 1;
	}
	return (nptr);
}

static int	_check_atof_limit(const char *nptr, size_t limit)
{
	nptr = ft_skip_charsets(nptr, SPACE_CHARSETS);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (*nptr == '.')
		return (ERROR);
	nptr = ft_skip_charsets(nptr, "0");
	nptr = _skip_digit(nptr, &limit);
	if (ft_is_equal_str(nptr, "."))
		return (ERROR);
	if (*nptr == '.')
		nptr++;
	nptr = _skip_digit(nptr, &limit);
	if (*nptr != '\0')
		return (ERROR);
	else
		return (SUCCESS);
}

int	try_atof_limit(const char *nptr, double *dptr, size_t limit)
{
	if (_check_atof_limit(nptr, limit) == ERROR)
		return (ERROR);
	*dptr = ft_atof(nptr);
	return (SUCCESS);
}
