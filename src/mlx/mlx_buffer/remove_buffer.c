/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:51:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 19:55:47 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include <stddef.h>

int	remove_buffer(char *buffer)
{
	const size_t	buffer_len = ft_strlen(buffer);

	if (buffer_len == 0)
		return (ERROR);
	buffer[buffer_len - 1] = '\0';
	return (buffer_len - 1);
}
