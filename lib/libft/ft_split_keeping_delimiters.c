/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_keeping_delimiters.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:13:12 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 00:11:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	_const_strings_size(const char *str, const char *set)
{
	size_t		strings_size;
	const char	*tmp;

	strings_size = 0;
	while (*str != '\0')
	{
		tmp = ft_skip_charsets(str, set);
		if (tmp != str)
		{
			strings_size++;
			str = tmp;
		}
		if (*str == '\0')
			break ;
		str = ft_skip_non_charsets(str, set);
		strings_size++;
	}
	return (strings_size);
}

static void	_fill_strings(const char *str, const char *set, char **strings)
{
	const char	*start;

	start = str;
	while (*str != '\0')
	{
		str = ft_skip_charsets(str, set);
		if (start != str)
		{
			*(strings++) = ft_strndup(start, (str - start));
			start = str;
		}
		if (*str == '\0')
			break ;
		str = ft_skip_non_charsets(str, set);
		*(strings++) = ft_strndup(start, (str - start));
		start = str;
	}
}

/**
* @brief Splitting a string by set of delimiters using a set,
*		 and creating an array of string, includeing the delimiter characters.
*
* @param str The string to be split.
* @param set The set of characters used as delimiters for spliting.
*/
char	**ft_split_keeping_delimiters(const char *str, const char *set)
{
	char	**strings;
	size_t	strings_size;

	strings_size = _const_strings_size(str, set);
	strings = (char **)ft_xcalloc(strings_size + 1, sizeof(char *));
	_fill_strings(str, set, strings);
	return (strings);
}
