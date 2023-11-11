/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key_and_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:44:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 18:03:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include <stddef.h>

static void	_put_list(char **list, int fd)
{
	size_t	idx;

	idx = 0;
	while (list[idx] != NULL)
	{
		ft_putstr_fd(list[idx], fd);
		if (list[idx + 1] != NULL)
			ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
		idx++;
	}
}

void	put_key_and_list(const char *key,
						const char *value,
						bool is_with_comma,
						int fd)
{
	char	**list;

	if (is_with_comma)
		ft_putendl_fd(GENERATOR_COMMA, fd);
	list = ft_split(value, RT_VECTOR_SEPARATOR);
	put_indent(2, fd);
	put_key_and_colon(key, fd);
	ft_putstr_fd(GENERATOR_LIST_START, fd);
	if (ft_strings_len((const char **)list) == 0)
		ft_putstr_fd(value, fd);
	else
		_put_list(list, fd);
	ft_putstr_fd(GENERATOR_LIST_END, fd);
	ft_free_strings(list);
}
