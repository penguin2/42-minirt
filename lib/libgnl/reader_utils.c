/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:09:42 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 16:09:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"
#include <stdlib.h>

int	reader_init(t_reader **preader, int fd)
{
	t_reader	*new_reader;

	*preader = NULL;
	new_reader = (t_reader *)malloc(1 * sizeof(t_reader));
	if (new_reader == NULL)
		return (-1);
	new_reader->fd = fd;
	new_reader->size = 0;
	new_reader->cur = 0;
	new_reader->buf = (char *)malloc(READER_BUFFER_SIZE * sizeof(char));
	if (new_reader->buf == NULL)
	{
		reader_free(&new_reader);
		return (-1);
	}
	*preader = new_reader;
	return (0);
}

void	reader_free(t_reader **preader)
{
	t_reader	*reader;

	if (preader == NULL || *preader == NULL)
		return ;
	reader = *preader;
	*preader = NULL;
	if (reader->buf != NULL)
		free(reader->buf);
	free(reader);
}

ssize_t	reader_fill_buffer(t_reader *reader)
{
	ssize_t	read_size;

	read_size = read(reader->fd, reader->buf, READER_BUFFER_SIZE);
	if (read_size == -1)
		return (-1);
	reader->size = (size_t)read_size;
	reader->cur = 0;
	return (read_size);
}
