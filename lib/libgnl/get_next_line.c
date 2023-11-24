/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:52:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 17:30:42 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"

char	*get_next_line(int fd, t_gnl_mode mode)
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
		return (reader_read(&reader, set_one_line));
	if (mode == GNL_MODE_ALL)
		return (reader_read(&reader, set_all));
	return (NULL);
}
