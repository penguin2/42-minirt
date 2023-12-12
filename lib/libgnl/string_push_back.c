/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:27:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 16:27:37 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"

int	string_push_back(t_string *str, char c)
{
	char	*dst;
	size_t	new_capacity;

	if (str->size == str->capacity)
	{
		if (str->capacity == (SIZE_MAX - 1))
			return (-1);
		if (str->capacity > (SIZE_MAX - 1) / 2)
			new_capacity = (SIZE_MAX - 1);
		else
			new_capacity = str->capacity * 2;
		dst = (char *)malloc(new_capacity * sizeof(char));
		if (dst == NULL)
			return (-1);
		string_memcpy(dst, str->content, str->size);
		free(str->content);
		str->content = dst;
		str->capacity = new_capacity;
	}
	(str->content)[(str->size)++] = c;
	return (0);
}

int	string_push_back_str(t_string *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (string_push_back(dst, src[i]) == -1)
			return (-1);
		++i;
	}
	return (0);
}
