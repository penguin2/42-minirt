/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:12:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 00:58:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ftoa(double number, size_t limit)
{
	char	*str;
	char	*str_integer;
	size_t	idx;

	str = (char *)ft_xcalloc(limit + 1, sizeof(char));
	str_integer = ft_itoa((int)number);
	idx = ft_strlcpy(str, str_integer, limit + 1);
	free(str_integer);
	str[idx++] = '.';
	while (idx < limit)
	{
		number *= 10;
		str[idx++] = (int)number % 10;
	}
	return (str);
}
