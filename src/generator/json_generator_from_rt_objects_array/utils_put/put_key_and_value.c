/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key_and_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:32:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 18:03:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include <stdbool.h>

void	put_key_and_value(const char *key,
							const char *value,
							bool is_with_comma,
							int fd)
{
	if (is_with_comma)
		ft_putendl_fd(GENERATOR_COMMA, fd);
	put_indent(2, fd);
	put_key_and_colon(key, fd);
	ft_putstr_fd(value, fd);
}
