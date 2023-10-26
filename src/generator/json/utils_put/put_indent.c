/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_indent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:30:31 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/26 19:34:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include <stddef.h>

void	put_indent(size_t nest_level, bool only_val_flag, int fd)
{
	size_t	idx;

	if (only_val_flag)
		return ;
	idx = 0;
	while (idx < nest_level)
	{
		ft_putstr_fd(INDENT_STR, fd);
		idx++;
	}
}
