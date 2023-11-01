/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_value_separator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:24:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 15:14:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include <stdbool.h>

void	put_value_separator(bool is_with_comma, size_t fd)
{
	if (is_with_comma)
		ft_putstr_fd(GENERATOR_COMMA, fd);
	ft_putchar_fd('\n', fd);
}
