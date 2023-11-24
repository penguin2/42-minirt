/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:44:16 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 02:07:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"
#include <stddef.h>

ssize_t	string_init(t_string **pstr, size_t capacity)
{
	t_string	*str;

	if (capacity == 0)
		return (-1);
	*pstr = NULL;
	str = (t_string *)malloc(1 * sizeof(t_string));
	if (str == NULL)
		return (-1);
	str->content = (char *)malloc(capacity * sizeof(char));
	if (str->content == NULL)
	{
		free(str);
		return (-1);
	}
	str->capacity = capacity;
	str->size = 0;
	*pstr = str;
	return (0);
}

void	string_free(t_string **pstr)
{
	t_string	*str;

	if (pstr == NULL || *pstr == NULL)
		return ;
	str = *pstr;
	*pstr = NULL;
	free(str->content);
	free(str);
}

char	*string_to_cstring(const t_string *str)
{
	char	*content;

	content = (char *)malloc((str->size + 1) * sizeof(char));
	if (content == NULL)
		return (NULL);
	string_memcpy(content, str->content, str->size);
	content[str->size] = '\0';
	return (content);
}

void	*string_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*unsigned_dst;
	const unsigned char	*unsigned_src;

	if (dst == src)
		return (dst);
	unsigned_dst = (unsigned char *)dst;
	unsigned_src = (const unsigned char *)src;
	while (0 < n)
	{
		*unsigned_dst++ = *unsigned_src++;
		n--;
	}
	return (dst);
}
