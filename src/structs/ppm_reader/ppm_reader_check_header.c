/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader_check_header.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:24:30 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 17:41:47 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "ppm_reader.h"
#include "utils.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

static int	_check_format_str(int fd);
static int	_check_width_height(int fd, int *pwidth, int *pheight);
static int	_free_strings_return(char **strs, int ret);
static int	_check_max_color_value(int fd);

int	ppm_reader_check_header(t_ppm_reader *new, int fd)
{
	if (_check_format_str(fd) == ERROR
		|| _check_width_height(fd, &new->width, &new->height) == ERROR
		|| _check_max_color_value(fd) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	_check_format_str(int fd)
{
	char	*line;
	bool	is_ok;

	line = ppm_reader_get_next_line(fd);
	is_ok = ft_is_equal_str(line, PPM_P6_FORMAT_STR);
	free(line);
	return (is_ok);
}

static int	_check_width_height(int fd, int *pwidth, int *pheight)
{
	char	**splits;
	int		width;
	int		height;
	char	*line;

	line = ppm_reader_get_next_line(fd);
	splits = ft_split(line, PPM_P6_SPACE_STR);
	free(line);
	if (ft_strings_len(splits) != 2
		|| convert_str_to_positive_int(splits[0], &width) == ERROR
		|| convert_str_to_positive_int(splits[1], &height) == ERROR
		|| !(width > 0 && height > 0
			&& width <= INT_MAX / PPM_P6_BYTES_PER_COLOR / height))
		return (_free_strings_return(splits, ERROR));
	*pwidth = width;
	*pheight = height;
	return (_free_strings_return(splits, SUCCESS));
}

static int	_free_strings_return(char **strs, int ret)
{
	ft_free_strings(strs);
	return (ret);
}

static int	_check_max_color_value(int fd)
{
	char	*line;
	bool	is_ok;

	line = ppm_reader_get_next_line(fd);
	is_ok = ft_is_equal_str(line, PPM_P6_MAX_COLOR_VALUE_STR);
	free(line);
	return (is_ok);
}
