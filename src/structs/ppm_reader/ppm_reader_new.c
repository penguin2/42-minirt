/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:37:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/13 16:57:51 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "ppm_reader.h"
#include "libgnl.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void	*_free_close_return_null(void *new_ptr, void *data, int fd);

t_ppm_reader	*ppm_reader_new(const char *filename)
{
	int				fd;
	unsigned char	*data;
	size_t			data_size;
	t_ppm_reader	*new;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (NULL);
	}
	new = ft_xcalloc(1, sizeof(t_ppm_reader));
	if (ppm_reader_check_header(new, fd) == ERROR)
		return (_free_close_return_null(new, NULL, fd));
	data = (unsigned char *)get_next_line(fd, &data_size, GNL_MODE_ALL);
	if (!(data != NULL && new->width > 0 && new->height > 0
			&& data_size == (size_t)new->width * new->height * 3))
		return (_free_close_return_null(new, data, fd));
	new->data = data;
	new->filename = ft_strdup(filename);
	_free_close_return_null(NULL, NULL, fd);
	return (new);
}

static void	*_free_close_return_null(void *new_ptr, void *data, int fd)
{
	if (new_ptr != NULL)
		free(new_ptr);
	if (data != NULL)
		free(data);
	close(fd);
	get_next_line(fd, NULL, GNL_MODE_RESET);
	return (NULL);
}
