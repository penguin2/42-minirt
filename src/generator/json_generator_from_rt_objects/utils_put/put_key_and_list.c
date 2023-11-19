/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key_and_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:44:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 11:01:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include <stddef.h>

/**
* @brief Output a comma-separated string of ft_split strings
*		 with commas as delimiters.
*		 if the first or last character of the string
*		 before being ft_split is a comma,
*		 ignoring whitespace, a comma is also output for that character.
*
* @param list Strings of splited comma.
* @param value String before the list is split.
*		 value is not empty string.
* @param fd Output destination file descriptor.
*/
static void	_put_list(char **list, const char *value, int fd)
{
	size_t	idx;

	idx = 0;
	if (*value == ',')
	{
		ft_putstr_fd(RT_VECTOR_SEPARATOR, fd);
		ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
	}
	while (list[idx] != NULL)
	{
		ft_putstr_fd(list[idx], fd);
		if (list[idx + 1] != NULL)
			ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
		idx++;
	}
	if (value[ft_strlen(value) - 1] == ',')
		ft_putstr_fd(RT_VECTOR_SEPARATOR, fd);
}

/**
* @brief Split the second argument value with a comma
*		 and generate the string in the format "KEY: [VALUES]".
*		 if nothing remains after ft_split the value,
*		 output the value before the split in the form "KEY: VALUE".
*
* @param key Key string
* @param value Value string
* @param is_with_comma Flag whether comma is output or not.
* @param fd Output destination file descriptor.
*/
void	put_key_and_list(const char *key,
						const char *value,
						bool is_with_comma,
						int fd)
{
	char	**list;

	if (is_with_comma)
		ft_putendl_fd(GENERATOR_COMMA, fd);
	put_indent(2, fd);
	put_key_and_colon(key, fd);
	ft_putstr_fd(GENERATOR_LIST_START, fd);
	list = ft_split(value, RT_VECTOR_SEPARATOR);
	if (ft_strings_len((const char **)list) == 0)
		ft_putstr_fd(value, fd);
	else
		_put_list(list, value, fd);
	ft_putstr_fd(GENERATOR_LIST_END, fd);
	ft_free_strings(list);
}
