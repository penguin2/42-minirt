/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_chars_in_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:19:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:30:38 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	*_error_read(char *all_chars)
{
	perror("read");
	if (all_chars == NULL)
		free(all_chars);
	return (NULL);
}

static char	*_set_all_chars_ptr_to_tmp(char *tmp, char *all_chars)
{
	if (tmp != NULL)
		free(tmp);
	return (all_chars);
}

char	*get_all_chars_in_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*all_chars;
	char	*tmp;
	int		read_return_val;

	tmp = NULL;
	all_chars = NULL;
	while (true)
	{
		ft_memset(&buffer, 0, BUFFER_SIZE + 1);
		read_return_val = read(fd, buffer, BUFFER_SIZE);
		if (read_return_val == 0 || read_return_val == -1)
			break ;
		all_chars = ft_strjoin(tmp, buffer);
		tmp = _set_all_chars_ptr_to_tmp(tmp, all_chars);
	}
	if (read_return_val == -1)
		all_chars = _error_read(all_chars);
	return (all_chars);
}
