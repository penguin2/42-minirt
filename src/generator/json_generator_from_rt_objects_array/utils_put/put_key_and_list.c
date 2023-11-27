/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key_and_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:44:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/23 23:59:45 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include <stddef.h>

/**
* @brief Spliting the value string by commas,
*		 appending a space after each odd-numbered values,
*		 and outputting to a specified file descriptor.
*
* @param value String before the list is split.
*		 value is not empty string.
* @param fd Output destination file descriptor.
*/
static void	_put_content(const char *value, int fd)
{
	size_t	idx;
	char	**list;

	list = ft_split_keeping_delimiters(value, RT_VECTOR_SEPARATOR);
	idx = 0;
	while (list[idx] != NULL)
	{
		ft_putstr_fd(list[idx], fd);
		if (idx % 2 == 1)
			ft_putchar_fd(' ', fd);
		idx++;
	}
	ft_free_strings(list);
}

/**
* @brief Split the second argument value with a commas
*		 and generate the stirng in the format
*		 "KEY: ['SPLITED_VALUE1''SPLITED_VALUE2''SPACE' ...]"
*		 if VALUE conforms to the expected list format,
*		 The output will look like "KEY: [VALUE, ...]".
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
	if (is_with_comma)
		ft_putendl_fd(GENERATOR_COMMA, fd);
	put_indent(2, fd);
	put_key_and_colon(key, fd);
	ft_putstr_fd(GENERATOR_LIST_START, fd);
	_put_content(value, fd);
	ft_putstr_fd(GENERATOR_LIST_END, fd);
}
