/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_removed_comment_line.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:42:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/28 23:11:40 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"
#include "parse.h"
#include <stddef.h>

char	*get_next_removed_comment_line(int fd)
{
	char	*line;

	line = get_next_line(fd, NULL, GNL_MODE_NEWLINE);
	if (line == NULL)
		return (NULL);
	line = delete_commentout(line, COMMENTOUT_STRING);
	return (line);
}
