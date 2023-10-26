/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_value_separator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:24:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/26 19:47:28 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include <stdbool.h>

void	put_value_separator(bool last_val_flag, bool only_val_flag, size_t fd)
{
	if (only_val_flag && !last_val_flag)
		ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
	else if (!only_val_flag)
	{
		if (!last_val_flag)
			ft_putstr_fd(GENERATOR_COMMA, fd);
		ft_putchar_fd('\n', fd);
	}
}
