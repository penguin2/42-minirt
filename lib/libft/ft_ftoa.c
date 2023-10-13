/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:12:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 16:16:40 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ftoa(double number, size_t limit)
{
	char	*str;
	char	*str_integer;
	size_t	idx;

	str_integer = ft_ltoa((long int)number);
	idx = ft_strlen(str_integer);
	str = (char *)ft_xcalloc(idx + limit + 2, sizeof(char));
	ft_strlcpy(str, str_integer, idx + 1);
	free(str_integer);
	str[idx++] = '.';
	number -= (long int)number;
	while (0 < limit)
	{
		limit--;
		number *= 10;
		str[idx++] = ((long int)number % 10) + '0';
		number -= (long int)number;
	}
	return (str);
}
