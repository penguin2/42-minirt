/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_chars_in_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:19:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 15:41:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

char	*get_all_chars_in_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*all_chars;
	char	*tmp;

	tmp = NULL;
	all_chars = NULL;
	while (1)
	{
		ft_memset(&buffer, 0, BUFFER_SIZE + 1);
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			break ;
		all_chars = ft_strjoin(tmp, buffer);
		if (tmp != NULL)
			free(tmp);
		tmp = all_chars;
	}
	return (all_chars);
}
