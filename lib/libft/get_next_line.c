/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:10:56 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 17:04:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

static char	*_remove_before_lf(char *str, char *buffer)
{
	char	*lf_ptr;

	lf_ptr = ft_strchr(buffer, '\n');
	if (lf_ptr != NULL)
	{
		lf_ptr++;
		while (*lf_ptr != '\0')
			*buffer++ = *lf_ptr++;
	}
	*buffer = '\0';
	return (str);
}

static char	*_reached_eof(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

static char	*_strjoin_to_lf(char *str, char *buffer)
{
	char	*new_str;
	char	*lf_ptr;
	char	*new_buffer;

	lf_ptr = ft_strchr(buffer, '\n');
	if (lf_ptr == NULL)
		new_str = ft_strjoin(str, buffer);
	else
	{
		new_buffer = ft_strndup(buffer, lf_ptr - buffer + 1);
		new_str = ft_strjoin(str, new_buffer);
		free(new_buffer);
	}
	if (str != NULL)
		free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		size;
	char		*str;

	str = _strjoin_to_lf(NULL, buffer);
	if (ft_strchr(buffer, '\n') != NULL)
		return (_remove_before_lf(str, buffer));
	while (true)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
		{
			if (str[0] == '\0')
				return (_reached_eof(str));
			else
				return (_remove_before_lf(str, buffer));
		}
		buffer[size] = '\0';
		if (ft_strchr(buffer, '\n') != NULL)
			return (_remove_before_lf(_strjoin_to_lf(str, buffer), buffer));
		str = _strjoin_to_lf(str, buffer);
	}
}
