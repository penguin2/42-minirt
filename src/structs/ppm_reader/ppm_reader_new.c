/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:37:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 21:07:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "ppm_reader.h"
#include "libgnl.h"
#include <fcntl.h>
#include <unistd.h>

static void	*_free_close_return_null(void *ptr, int fd);

t_ppm_reader	*ppm_reader_new(const char *filename)
{
	int				fd;
	char			*data;
	t_ppm_reader	*new;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	new = ft_xcalloc(1, sizeof(t_ppm_reader));
	if (ppm_reader_check_header(new, fd) == ERROR)
		return (_free_close_return_null(new, fd));
	data = get_next_line(fd, GNL_MODE_ALL);
	if (data == NULL)
		return (_free_close_return_null(new, fd));
	new->data = data;
	return (new);
}

static void	*_free_close_return_null(void *ptr, int fd)
{
	free(ptr);
	close(fd);
	return (NULL);
}
