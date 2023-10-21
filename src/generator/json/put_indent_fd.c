/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_indent_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:30:31 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:50:10 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>

void	put_indent_fd(int fd, size_t nest_level)
{
	size_t	idx;

	idx = 0;
	while (idx < nest_level)
	{
		ft_putstr_fd(INDENT_STR, fd);
		idx++;
	}
}
