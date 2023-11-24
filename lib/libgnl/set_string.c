/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:22:27 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 17:27:01 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"
#include <stdbool.h>

int	set_one_line(t_reader *reader, t_string *string)
{
	ssize_t	read_size;
	char	c;

	while (true)
	{
		if (reader->cur == reader->size)
		{
			read_size = reader_fill_buffer(reader);
			if (read_size == -1 || (read_size == 0 && string->size == 0))
				return (-1);
			if (read_size == 0)
				break ;
		}
		c = (reader->buf)[(reader->cur)++];
		if (c == '\n')
			return (0);
		if (string_push_back(string, c) == -1)
			return (-1);
	}
	return (0);
}

int	set_all(t_reader *reader, t_string *string)
{
	ssize_t	read_size;

	while (true)
	{
		if (reader->cur == reader->size)
		{
			read_size = reader_fill_buffer(reader);
			if (read_size == -1 || (read_size == 0 && string->size == 0))
				return (-1);
			if (read_size == 0)
				break ;
		}
		if (string_push_back_str(string, reader->buf + reader->cur,
				reader->size - reader->cur) == -1)
			return (-1);
		reader->cur = reader->size;
	}
	return (0);
}
