/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader_get_next_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:33:26 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 17:25:40 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libgnl.h"
#include "ppm_reader.h"
#include <stdbool.h>

static bool	_is_startswith(const char *str, const char *target);

char	*ppm_reader_get_next_line(int fd)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd, NULL, GNL_MODE_NEWLINE);
		if (line == NULL || !_is_startswith(line, PPM_P6_COMMENT_STR))
			break ;
		free(line);
	}
	return (line);
}

static bool	_is_startswith(const char *str, const char *target)
{
	return (ft_is_equal_str_n(str, target, ft_strlen(target)));
}
