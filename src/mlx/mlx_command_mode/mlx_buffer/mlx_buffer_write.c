/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buffer_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:45:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/05 16:35:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "mlx_command_mode.h"
#include <stddef.h>
#include <unistd.h>

int	mlx_buffer_write(char *buffer, int c)
{
	const size_t	buffer_len = ft_strlen(buffer);

	if (buffer_len == MLX_BUFFER_SIZE - 1)
	{
		ft_putchar_fd('\a', STDOUT_FILENO);
		return (ERROR);
	}
	buffer[buffer_len] = c;
	buffer[buffer_len + 1] = '\0';
	return (buffer_len);
}
