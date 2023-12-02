/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:45:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 20:40:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include <stddef.h>
#include <unistd.h>

int	write_buffer(char *buffer, int c, size_t buffer_max_size)
{
	const size_t	buffer_len = ft_strlen(buffer);

	if (buffer_len == 0)
		return (ERROR);
	else if (buffer_len == buffer_max_size - 1)
	{
		ft_putchar_fd('\a', STDOUT_FILENO);
		return (ERROR);
	}
	buffer[buffer_len] = c;
	buffer[buffer_len + 1] = '\0';
	return (buffer_len);
}
