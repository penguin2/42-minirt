/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:52:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 17:17:39 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"

char	*get_next_line(int fd, size_t *read_size, t_gnl_mode mode)
{
	static t_reader	*reader;

	if (mode == GNL_MODE_RESET)
	{
		reader_free(&reader);
		return (NULL);
	}
	if (reader == NULL && reader_init(&reader, fd) == -1)
		return (NULL);
	if (mode == GNL_MODE_NEWLINE)
		return (reader_read(&reader, read_size, set_one_line));
	if (mode == GNL_MODE_ALL)
		return (reader_read(&reader, read_size, set_all));
	return (NULL);
}
