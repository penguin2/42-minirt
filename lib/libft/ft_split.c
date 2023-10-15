/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:21:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/16 21:52:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	_count_strings_size(const char *str, const char *set)
{
	size_t	strings_size;

	strings_size = 0;
	while (*str != '\0')
	{
		str = ft_skip_charsets(str, set);
		if (*str == '\0')
			break ;
		strings_size++;
		str = ft_skip_non_charsets(str, set);
	}
	return (strings_size);
}

static void	_fill_strings(const char *str, const char *set, char **strings)
{
	const char	*start;

	while (*str != '\0')
	{
		str = ft_skip_charsets(str, set);
		if (*str == '\0')
			break ;
		start = str;
		str = ft_skip_non_charsets(str, set);
		*(strings++) = ft_strdup_n(start, (str - start));
	}
}

char	**ft_split(const char *str, const char *set)
{
	char	**strings;
	size_t	strings_size;

	strings_size = _count_strings_size(str, set);
	strings = (char **)ft_xcalloc(strings_size + 1, sizeof(char *));
	_fill_strings(str, set, strings);
	return (strings);
}
