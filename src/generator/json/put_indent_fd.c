/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_indent_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:30:31 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/20 15:38:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

void	put_indent_fd(size_t nest_level, int fd)
{
	size_t	idx;

	idx = 0;
	while (idx++ < nest_level)
		ft_putstr_fd(INDENT_STR, fd);
}
