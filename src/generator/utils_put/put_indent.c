/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_indent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:30:31 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/27 21:08:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include <stddef.h>

void	put_indent(size_t nest_level, int fd)
{
	size_t	idx;

	idx = 0;
	while (idx < nest_level)
	{
		ft_putstr_fd(INDENT_STR, fd);
		idx++;
	}
}
